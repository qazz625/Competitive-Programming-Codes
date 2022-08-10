#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

vector<int> buildSegTree(vector<int> &v){
	while((1<<30)%v.size() != 0)
		v.push_back(1);


	vector<int> segtree(2*v.size());
	for(int i=0; i<v.size(); i++){
		segtree[i+v.size()] = v[i];
	}

	for(int i=segtree.size()-1; i!=1; i-=2){
		if(segtree[i] == 0 && segtree[i-1] == 0){
			segtree[i/2] = 0;
		}
		else
			segtree[i/2] = __gcd(segtree[i], segtree[i-1]);
	}

	return segtree;
}

int query(vector<int> &segtree, int l, int r, int x, int y, int ind){
	if(r < x || l > y){
		return 0;
	}
	else if(x >= l && y <= r){
		return segtree[ind];
	}
	else{
		int mid = (x+y)/2;
		int one = query(segtree, l ,r ,x, mid, 2*ind);
		int two = query(segtree, l, r, mid+1, y, 2*ind+1);
		return __gcd(one, two);
	}
}



int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];


		if(n == 1){
			cout << "1\n";
			continue;
		}

		vector<int> v;
		for(int i=0; i<n-1; i++){
			v.push_back(abs(arr[i+1]-arr[i]));
		}

		// print(v);

		vector<int> segtree = buildSegTree(v);

		int res = 0;
		for(int i=0; i<n-1; i++){
			int start = i, end = n-2, ans = -1;
			while(start <= end){
				int mid = (start+end)/2;
				int a = query(segtree, i, mid, 0, v.size()-1, 1);
				if(a > 1){
					ans = mid;
					start = mid+1;
				}
				else{
					end = mid-1;
				}
			}
			// debug(i, ans);
			res = max(res, ans-i+1 + 1);
		}

		cout << res << "\n";

	}

}

//Read the stuff at the top