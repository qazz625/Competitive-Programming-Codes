#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int t;
	cin >> t;
	set<int> goals;
	for(int i=0; i<30; i++){
		goals.insert((1<<i)-1);
	}

	while(t--){
		int n, k;
		cin >> n >> k;
		// debug(n, k);
		int totxor = 0;
		for(int i=1; i<=n; i++)
			totxor ^= i;

		if(k == 1){
			cout << n;
		}
		else if(k == n){
			for(int i=1; i<=n; i++)
				cout << i << " ";
		}
		else if(k == n-1){
			int ans = -1, ind = -1;
			// debug(totxor);
			for(int i=1; i<=n; i++){
				if((totxor^i) > ans){
					ans = totxor^i;
					ind = i;
				}
			}
			for(int i=1; i<=n; i++)
				if(ind != i)
					cout << i << " ";
		}
		else{
			int maxxor, goal, inv = 0;
			if(goals.find(n) != goals.end())
				maxxor = n;
			else
				maxxor = *goals.upper_bound(n);

			if(n == maxxor-1 && k == n-2){
				maxxor = n;
			}

			if(k > n/2){
				goal = totxor^maxxor;
				k = n-k;
				inv = 1;
			}
			else{
				goal = maxxor;
			}

			vector<int> v;
			for(int j=1; j<=n; j++)
				v.push_back(j);


			int done = 0;
			vector<int> ans;
			for(int i=0; i<100 && done == 0; i++){
				ans.clear();

				random_shuffle(v.begin(), v.end());

				int cur = 0;
				for(int j=0; j<k-1; j++){
					cur ^= v[j];
					ans.push_back(v[j]);
				}
				for(int j=k-1; j<n; j++){
					if((cur^v[j]) == goal){
						done = 1;
						ans.push_back(v[j]);
						break;
					}
				}
			}

			assert(done == 1);

			if(inv == 0){
				for(int i=0; i<ans.size(); i++)
					cout << ans[i] << " ";
			}
			else{
				vector<int> present(n+1);
				for(int i=0; i<ans.size(); i++)
					present[ans[i]] = 1;

				for(int i=1; i<=n; i++){
					if(present[i] == 0)
						cout << i << " ";
				}
			}
		}
		cout << "\n";
	}
}
