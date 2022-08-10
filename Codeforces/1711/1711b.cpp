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
		int arr[n];
		int tot = 0;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			tot += arr[i];
		}

		int ans = 0;
		vector<pair<int, int>> edges;
		int degrees[n] = {0};
		for(int i=0; i<m; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			degrees[u]++;
			degrees[v]++;
			edges.push_back({u, v});
		}

		if(m%2 == 0){
			cout << 0 << "\n";
			continue;
		}
		// print(edges);
		// print(degrees, n);

		for(int i=0; i<m; i++){
			if(degrees[edges[i].first]%2 == 0 && degrees[edges[i].second]%2 == 0){
				ans = max(ans, tot - arr[edges[i].first] - arr[edges[i].second]);
			}
		}

		for(int i=0; i<n; i++){
			if(degrees[i]%2){
				ans = max(ans, tot - arr[i]);
			}
		}

		cout << tot-ans << "\n";
	}


}

