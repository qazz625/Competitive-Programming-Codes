#include <bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int arr[n];
		map<int, int> mp;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			mp[arr[i]]++;
		}

		set<pair<int, int>> s;
		for(int i=0; i<m; i++){
			int u, v;
			cin >> u >> v;
			s.insert({u, v});
			s.insert({v, u});
		}

		map<int, vector<int>> freq;
		for(auto x: mp){
			freq[x.second].push_back(x.first);
		}
		for(auto x: freq){
			sort(x.second.begin(), x.second.end());
		}

		// for(auto x: freq){
		// 	cout << x.first << ": ";
		// 	print(x.second);
		// }

		set<int> done;

		long long ans = -1;
		for(int i=0; i<n; i++){
			if(done.find(arr[i]) == done.end()){
				int x = arr[i];
				int cntx = mp[arr[i]];
				for(auto y: freq){
					for(int j=y.second.size()-1; j>=0; j--){
						if(y.second[j] != x && s.find({x, y.second[j]}) == s.end()){
							long long temp = (long long)(x+y.second[j]) * (cntx+y.first);
							ans = max(ans, temp);
							break;
						}
					}
				}
				done.insert(arr[i]);
			}
		}

		cout << ans << "\n";
	}
}

