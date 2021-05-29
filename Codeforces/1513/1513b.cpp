#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod = 1000000007;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int fact[1000000];


int32_t main(){
	int t;
	cin >> t;
	fact[0] = 1;
	for(int i=1; i<1000000; i++){
		fact[i] = fact[i-1]*i % mod;
	}
	// print(fact, 10);
	while(t--){
		int n;
		cin >> n;
		map<int, int> mp;
		set<int> allones;
		int ones[35] = {0};
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			for(int j=0; j<35; j++){
				if(x&(1ll<<(34-j)))
					ones[34-j]++;
			}
			mp[x] += 1;
		}

		for(int i=0; i<35; i++)
			if(ones[i] == n)
				allones.insert(i);

		// print(ones, 35);
		// print(allones);
		// print(mp);

		int ans = 0;
		for(auto x: mp){
			int flag = 0;
			if(x.second >= 2){
				for(int i=0; i<35; i++){
					if( (x.first&(1ll<<(34-i))) && allones.find(34-i) == allones.end()){
						flag = 1;
					}
				}
				// debug(flag);
				if(flag == 0){
					int mult = x.second*(x.second-1) % mod;
					ans += fact[n-2]*mult % mod;
				}
			}
		}

		cout << ans%mod << "\n";

	}
}
