#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod = 1000000007;
int dp[300000][10];

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0; i<10; i++)
		dp[0][i] = 1;

	for(int i=1; i<250000; i++){
		dp[i][9] = (dp[i-1][1] + dp[i-1][0])%mod;
		for(int j=8; j>=0; j--)
			dp[i][j] = dp[i-1][j+1];
	}

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;

		int ans = 0;
		while(n != 0){
			ans += dp[m][n%10];
			n /= 10;
		}
		cout << ans%mod << "\n";
	}
}
