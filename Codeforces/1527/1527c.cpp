#include <bits/stdc++.h>
using namespace std;

#define int long long

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
		int n;
		cin >> n;
		int orin = n;
		map<int, vector<int>> mp;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			mp[x].push_back(i);
		}

		int ans = 0;
		for(auto x: mp){
			vector<int> temp = x.second;
			vector<int> suff(temp.size());
			int n = temp.size();
			suff[n-1] = temp[n-1];

			for(int i=n-2; i>=0; i--){
				suff[i] = suff[i+1] + temp[i];
			}
			// print(temp);
			// print(suff);
			// debug(x.first);
			int prev = -1;
			for(int i=0; i<n-1; i++){

				int val = (temp[i]+1)*((n-1-i)*orin - suff[i+1]);
				ans += val;
				// debug(val);
				prev = temp[i];
			}
		}
		cout << ans << "\n";

	}
}
