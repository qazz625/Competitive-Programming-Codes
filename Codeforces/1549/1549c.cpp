#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	t = 1;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> arr(n, 0);
		int ans = n;
		for(int i=0; i<m; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			if(u > v)
				swap(u, v);

			if(arr[u] == 0)
				ans--;
			arr[u]++;
		}

		// print(arr);

		int q;
		cin >> q;
		while(q--){
			int type;
			cin >> type;
			if(type == 1){
				int u, v;
				cin >> u >> v;
				u--; v--;
				if(u > v)
					swap(u, v);

				if(arr[u] == 0)
					ans--;
				arr[u]++;
			}

			else if(type == 2){
				int u, v;
				cin >> u >> v;
				u--; v--;
				if(u > v)
					swap(u, v);
				arr[u]--;
				if(arr[u] == 0)
					ans++;
			}

			else{
				cout << ans << "\n";
			}
		}
	}


}

//Read the stuff at the top