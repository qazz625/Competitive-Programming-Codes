/*
THINGS TO DO
1) Check integer overflows
2) Check corner cases
3) Compile and run once on terminal
4) Code smart, not quick
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int mod = 998244353;

int dp[510][510];

int powers[510][510];

int32_t main(){
	int n, x;
	cin >> n >> x;


	// for(int i=1; i<=n; i++){
	// 	dp[1][i] = n-i+1;
	// }

	for(int i=1; i<510; i++){
		powers[i][0] = 1;
		for(int j=1; j<510; j++){
			powers[i][j] = powers[i][j-1]*i;
			powers[i][j] %= mod;
		}
	}

	if(x < n){
		cout << powers[x][n] << "\n";
		return 0;
	}


	for(int i=2; i<=n; i++){
		for(int j=1; j<i; j++){
			//all die in first round
			dp[i][j] += powers[i-j][i];
			//k people die in first round
			for(int k=1; k<i; k++){
				dp[i][j] += powers[i-j][k]*powers[x-(i-j)][i-k];
				dp[i][j] %= mod;
				dp[i][j] *= dp[i-k][i];
				dp[i][j] %= mod;
			}
		}

		for(int j=i; j<=x; j++){
			for(int k=1; k<j; k++){
				dp[i][j] += dp[i][k];
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[n][1] << "\n";
}

//Read the stuff at the top