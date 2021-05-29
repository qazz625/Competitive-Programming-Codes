#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int stable[200010][19];
vector<int> next2pow(200010);

int inf = 1000000010;
int n, p;

int findgcd(int a, int b){
	int l = b-a+1;
	int one = stable[a][next2pow[l]];
	int two = stable[b-(1<<next2pow[l])+1][next2pow[l]];
	return __gcd(one, two);
}


void update(vector<int> &segtree, int l, int r, int x, int y, int ind, int val){
	if(r < x || l > y)
		return;
	else if(l >= x && r <= y){
		segtree[ind] = val;
	}
	else{
		int mid = (l+r)/2;
		update(segtree, l, mid, x, y, 2*ind, val);
		update(segtree, mid+1, r, x, y, 2*ind+1, val);
	}
}

int query(vector<int> &segtree, int ind){
	ind += segtree.size()/2;
	int ans = p;
	while(ind != 0){
		ans = min(ans, segtree[ind]);
		ind /= 2;
	}
	return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int cur = 0;
	for(int i=1; i<200010; i++){
		if(i >= 2*(1<<cur))
			cur += 1;
		next2pow[i] = cur;

	}
	// print(next2pow);

	while(t--){
		cin >> n >> p;
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		//gcd in 0
		//min in 1
		for(int i=0; i<n; i++){
			for(int j=0; j<19; j++){
				stable[i][j] = 0;
			}
		}

		for(int i=0; i<n; i++){
			stable[i][0] = arr[i];
		}

		for(int i=n-2; i>=0; i--){
			for(int j=1; i+(1<<j)-1<n; j++){
				stable[i][j] = __gcd(stable[i][j-1], stable[i+j][j-1]);
			}
		}

		vector<vector<int>> segments;


		for(int i=0; i<n; i++){
			int s = i, e = n-1, ans1 = -1;
			while(s <= e){
				int mid = (s+e)/2;
				int g = findgcd(i, mid);
				if(g == arr[i]){
					ans1 = mid;
					s = mid+1;
				}
				else{
					e = mid-1;
				}
			}

			s = 0, e = i;
			int ans2 = -1;
			while(s <= e){
				int mid = (s+e)/2;
				int g = findgcd(mid, i);
				if(g == arr[i]){
					ans2 = mid;
					e = mid-1;
				}
				else{
					s = mid+1;
				}
			}

			if(ans1 != ans2 && arr[i] < p)
				segments.push_back({arr[i], ans2, ans1});
		}

		if(segments.size() == 0){
			cout << (n-1)*p << "\n";
			continue;
		}

		sort(segments.begin(), segments.end());

		set<int> s;
		for(int i=1; i<n; i++)
			s.insert(i);

		print(segments);

		int ans = 0;
		for(auto x: segments){
			auto itr1 = s.lower_bound(x[1]);
			auto itr2 = s.upper_bound(x[2]);
			if(itr1 != s.end()){
				vector<int> temp;
				for(; itr1 != itr2; itr1++){
					temp.push_back(*itr1);
					ans += x[0];
				}
				for(auto x: temp)
					s.erase(x);
			}
			print(s);
		}

		// cout << "CC" << endl;
		cout << ans+p*s.size() << endl;
	}
}
