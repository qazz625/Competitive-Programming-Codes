#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

void update(vector<int> &segtree, int n){
	n += segtree.size()/2;
	while(n != 0){
		segtree[n] += 1;
		n /= 2;
	}
}

int query(vector<int> &segtree, int x, int y, int l, int r, int ind){
	if(y < l || x > r){
		return 0;
	}
	else if(x >= l && y <= r){
		return segtree[ind];
	}
	else{
		int mid = (x+y)/2;
		int a = query(segtree, x, mid, l, r, 2*ind);
		int b = query(segtree, mid+1, y, l, r, 2*ind+1);

		return a+b;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> arr(n*m);
		for(int i=0; i<n*m; i++){
			int x;
			cin >> x;
			arr[i] = {x, i/m, i%m};
		}

		vector<vector<int>> sorted = arr;
		sort(sorted.begin(), sorted.end());

		int prevval = sorted[0][0];
		sorted[0][0] = 0;
		for(int i=1; i<sorted.size(); i++){
			if(sorted[i][0] == prevval){
				sorted[i][0] = sorted[i-1][0];
			}
			else{
				prevval = sorted[i][0];
				sorted[i][0] = sorted[i-1][0] + 1;
			}
		}

		// print(arr);
		// print(sorted);



		map<int, vector<int>> mparr[n+10];

		for(int i=0; i<sorted.size(); i++){
			int row = i/m;
			int col = i%m;
			mparr[row][sorted[i][0]].push_back(i);

			arr[m*sorted[i][1] + sorted[i][2]][0] = sorted[i][0];
		}

		map<int, vector<int>> mp;

		for(int i=n; i>=0; i--){
			for(auto &x: mparr[i]){
				for(auto y: x.second){
					mp[x.first].push_back(y);
				}
			}
		}


		// print(sorted);
		int segtreesize = m;
		while((1<<30)%segtreesize != 0)
			segtreesize++;

		segtreesize *= 2;

		vector<int> segtreearr[n];

		for(int i=0; i<n; i++){
			vector<int> segtree(segtreesize);
			segtreearr[i] = segtree;
		}

		// for(auto x: mp){
		// 	debug(x.first);
		// 	print(x.second);
		// }
		// print(arr);
		// cout << endl;


		long long ans = 0;
		for(int i=0; i<n*m; i++){
			int num = arr[i][0];
			int ind = mp[num].back();
			mp[num].pop_back();
			int row = ind/m;
			ind %= m;
			int temp = query(segtreearr[row], 0, segtreesize/2-1, 0, ind, 1);
			ans += temp;
			update(segtreearr[row], ind);

			// print(segtree);
		}

		cout << ans << "\n";

	}


}

