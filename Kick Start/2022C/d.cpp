#include <bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE
// 	#define _GLIBCXX_DEBUG
// 	#include "../../../debug.cpp"
// #endif

#define int long long

int dp[410][410][410];
int mod = 1000000007;
int fact[500], invmod[500];

int C(int n, int r){
	int num = fact[n];
	int denom = invmod[r]*invmod[n-r] % mod;

	return num * denom % mod;
}


int binpow(int a, int b, int m){
	if(b == 0)
		return 1;

	int x = binpow(a, b/2, m);
	x = x*x % m;

	if(b%2 == 0)
		return x;
	else
		return x*a % m;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	fact[0] = 1;
	for(int i=1; i<500; i++)
		fact[i] = fact[i-1]*i % mod;

	for(int i=0; i<500; i++)
		invmod[i] = binpow(fact[i], mod-2, mod);




	for(int tt=0; tt<t; tt++){
		int n;
		cin >> n;
		string s;
		cin >> s;

		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++)
				for(int k=0; k<=n; k++)
					dp[i][j][k] = 0;

		for(int i=0; i<n; i++){
			dp[i][i][0] = 1;
			dp[i][i][1] = 1;
		}

		for(int i=0; i<n-1; i++){
			dp[i][i+1][1] = 2;
			dp[i][i+1][0] = 1;
			if(s[i] == s[i+1])
				dp[i][i+1][2] = 1;
		}


		for(int i=2; i<n; i++){
			for(int j=0; j<n-i; j++){
				if(s[j] == s[j+i]){
					for(int k=0; k<=n; k++){
						dp[j][j+i][k+2] += dp[j+1][j+i-1][k];
						dp[j][j+i][k] += dp[j+1][j+i][k];
						dp[j][j+i][k] += dp[j][j+i-1][k];
						dp[j][j+i][k] -= dp[j+1][j+i-1][k];
					}
				}
				else{
					for(int k=0; k<=n; k++){
						dp[j][j+i][k] += dp[j+1][j+i][k];
						dp[j][j+i][k] += dp[j][j+i-1][k];
						dp[j][j+i][k] -= dp[j+1][j+i-1][k];
					}
				}

				for(int k=0; k<=n; k++)
					dp[j][j+i][k] %= mod;
			}
		}

		int num = 0;
		int denom = invmod[n];
		for(int i=1; i<n; i++){

			int unit = fact[n]*binpow(C(n, i), mod-2, mod) % mod;
			num += dp[0][n-1][i]*unit;
			num %= mod;
		}

		num += fact[n];
		num %= mod;

		num = num*denom%mod;

		if(num < 0)
			num += mod;

		cout << "Case #" << tt+1 << ": " << num << "\n";

	}
}
