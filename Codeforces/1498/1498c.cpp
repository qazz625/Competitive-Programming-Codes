/*
THINGS TO DO
1) Check integer overflows
2) Check corner cases
3) Compile and run once on terminal
4) Code smart, not quick
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int mod = 1000000007;

int dp[1010][1010];

int binpower(int a, int b, int m){
	if(b == 0)
		return 1;

	int x = binpower(a, b/2, m);
	x *= x;
	x %= mod;
	if(b%2 == 0)
		return x%m;
	else
		return x*a % m;

}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i=0; i<n; i++)
			for(int j=0; j<k; j++)
				dp[i][j] = 0;

		if(k == 1){
			debug(1);
			continue;
		}

		int val[n];
		for(int i=0; i<n; i++){
			val[i] = i;
		}
		k -= 1;
		int ans = 1+n;

		for(int i=0; i<k; i++){
			for(int j=0; j<n; j++){
				ans += val[j];
				val[j] *= j;
				val[j] %= mod;
			}
			// print(val, n);
			ans %= mod;
		}
		debug(ans%mod);


	}


}

//Read the stuff at the top