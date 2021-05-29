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
int n, k;


void solve(int ind, int k){
	debug(ind, k);

	if(ind == n-1){
		return;
	}

	solve(ind+1, k);
	for(int i=k-1; i>=1; i--){
		for(int j=i; j>=1; j-=2){
			dp[ind][j] += dp[ind+1][i];
		}
	}
}

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
		cin >> n >> k;
		for(int i=0; i<n; i++)
			for(int j=0; j<=k; j++)
				dp[i][j] = 0;


		solve(0, k);

		
		for(int i=0; i<n; i++){
			for(int j=0; j<=k; j++){
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";

	}


}

//Read the stuff at the top