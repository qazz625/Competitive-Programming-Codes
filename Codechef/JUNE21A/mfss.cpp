#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int mod = 1000000007;
int mult = 998244353;
int inf = 1e18;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		assert(n <= 1010);
		vector<int> arr(n);
		for(int i=0; i<n; i++){
			cin >> arr[i];
			arr[i] += 1<<26;
		}

		map<int, pair<int, int>> mp[n+1];

		for(int i=0; i<n; i++){
			int val = 0;
			int sum = 0;
			for(int j=i; j<n; j++){
				val *= mult;
				val += arr[j];
				sum += arr[j];
				val = ((val%mod) + mod)%mod;
				mp[j-i+1][val].first++;
				mp[j-i+1][val].second = sum;
			}
		}

		// for(int i=0; i<=n; i++){
		// 	debug(i);
		// 	for(auto x: mp[i]){
		// 		cout << x.first << "\n";
		// 		cout << x.second.first << " " << x.second.second << "\n";
		// 	}
		// 	cout << "\n";
		// }

		int ans = -inf;
		
		for(int i=1; i<=n; i++){
			for(auto x: mp[i]){
				int occur = x.second.first;
				int tot = x.second.second;
				int sub = (1<<26)*i*occur;
				ans = max(ans, occur*tot - sub);
			}
		}
		cout << ans << "\n";

	}
}
