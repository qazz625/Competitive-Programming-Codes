#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod = 998244353;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

//USING 1 BASED INDEXING

int dp[600][600];


int32_t main(){
	int n;
	cin >> n;
	vector<pair<char, int>> arr(n+1);
	for(int i=1; i<=n; i++){
		cin >> arr[i].first;
		if(arr[i].first == '+')
			cin >> arr[i].second;
	}

	int ans = 0;

	for(int i=1; i<=n; i++){
		if(arr[i].first == '-')
			continue;

		//calculate number of ways to select x numbers less or equal to than a[j] from 1 to i-1
		for(int j=0; j<=n; j++)
			for(int k=0; k<=n; k++)
				dp[j][k] = 0;

		dp[0][0] = 1;
		for(int j=1; j<i; j++){
			//dont choose current element

			for(int k=0; k<=n; k++){
				dp[j][k] += dp[j-1][k];
				dp[j][k] %= mod;
			}
			

			//choose current
			if(arr[j].first == '-'){
				for(int k=0; k<=n-1; k++){
					dp[j][k] += dp[j-1][k+1];
					dp[j][k] %= mod;
				}
				dp[j][0] += dp[j-1][0];
				dp[j][0] %= mod;
			}
			else if(arr[j].second < arr[i].second){
				for(int k=1; k<=n; k++){
					dp[j][k] += dp[j-1][k-1];
					dp[j][k] %= mod;
				}
			}
			else{
				for(int k=0; k<=n; k++){
					dp[j][k] += dp[j-1][k];
					dp[j][k] %= mod;
				}
			}
		}
		for(int k=1; k<=n; k++){
			dp[i][k] += dp[i-1][k-1];
			dp[i][k] %= mod;
		}

		for(int j=i+1; j<=n; j++){
			//dont choose current element

			for(int k=0; k<=n; k++){
				dp[j][k] += dp[j-1][k];
				dp[j][k] %= mod;
			}
			

			//choose current
			if(arr[j].first == '-'){
				for(int k=0; k<=n-1; k++){
					dp[j][k] += dp[j-1][k+1];
					dp[j][k] %= mod;
				}
				dp[j][0] += dp[j-1][0];
				dp[j][0] %= mod;
			}
			else if(arr[j].second <= arr[i].second){
				for(int k=2; k<=n; k++){
					dp[j][k] += dp[j-1][k-1];
					dp[j][k] %= mod;
				}
			}
			else{
				for(int k=0; k<=n; k++){
					dp[j][k] += dp[j-1][k];
					dp[j][k] %= mod;
				}
			}
		}

		int tot = 0;
		for(int j=1; j<=n; j++){
			tot += dp[n][j];
			tot %= mod;
		}
		tot %= mod;

		ans += tot*arr[i].second;
		ans %= mod;
	}
	cout << ans << "\n";


}

