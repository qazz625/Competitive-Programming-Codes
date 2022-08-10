#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int dp[8000010];
int prefsum[8000010];

int32_t main(){
	int n, m;
	cin >> n >> m;
	dp[n] = 1;
	prefsum[n] = 1;

	for(int i=n-1; i>=1; i--){
		dp[i] += prefsum[i+1];
		for(int j=2; i*j <= n; j++)
			dp[i] += prefsum[i*j] - prefsum[(i+1)*j];

		dp[i] %= m;
		prefsum[i] = dp[i] + prefsum[i+1];
		prefsum[i] %= m;
	}
	cout << (dp[1]%m + m)%m << "\n";
}
