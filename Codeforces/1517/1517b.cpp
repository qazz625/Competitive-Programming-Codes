#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		multiset<int> arr[n];
		multiset<pair<int, int>> curmin;

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				int x;
				cin >> x;
				arr[i].insert(x);
			}
		}
		// debug("BB");

		for(int i=0; i<n; i++){
			curmin.insert({*arr[i].begin(), i});
		}

		// debug("AA");

		vector<vector<int>> ans(m, vector<int>(n, -1));

		for(int i=0; i<m; i++){
			pair<int, int> minval = *curmin.begin();

			int ind = minval.second;
			ans[i][ind] = minval.first;
			// print(minval);

			arr[ind].erase(arr[ind].begin());
			curmin.erase(curmin.begin());
			curmin.insert({*arr[ind].begin(), ind});

			for(int j=0; j<n; j++){
				if(j != ind){
					auto ptr = arr[j].end();
					ptr--;
					ans[i][j] = *ptr;
					arr[j].erase(ptr);
				}
			}
			// for(auto x: curmin){
			// 	print(x);
			// }
			// debug("AA");
		}		

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << ans[j][i] << " ";
			}
			cout << "\n";
		}
	}


}

//Read the stuff at the top