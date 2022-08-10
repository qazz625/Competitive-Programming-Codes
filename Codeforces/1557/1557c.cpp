#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int twopow[200010];

int mod = 1000000007;

int binpow(int a, int b, int mod){
	if(b == 0)
		return 1;

	int x = binpow(a, b/2, mod);
	x = x*x % mod;
	if(b%2 == 0)
		return x;
	else
		return x*a % mod;
}

int32_t main(){
	int t;
	cin >> t;

	twopow[0] = 1;
	for(int i=1; i<200010; i++){
		twopow[i] = twopow[i-1]*2;
		twopow[i] %= mod;
	}

	// print(twopow, 20);

	while(t--){
		int n, k;
		cin >> n >> k;

		if(n%2 == 1){
			int pref = 1;
			int ans = 0;
			for(int i=0; i<k; i++){
				int temp = (1+(twopow[n-1]));
				pref *= temp;
				pref %= mod;
			}
			cout << pref << "\n";
		}

		else{
			int pref = 1;
			int ans = 0;
			for(int i=0; i<k; i++){
				int temp = binpow(2, n*(k-(i+1)), mod);
				ans += pref * 1 * temp;
				pref *= (twopow[n-1]-1);
				ans %= mod;
				pref %= mod;
			}
			ans += pref;
			cout << ans%mod << "\n";
		}
	}


}

