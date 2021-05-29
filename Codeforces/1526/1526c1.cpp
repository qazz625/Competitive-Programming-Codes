#include <bits/stdc++.h>
using namespace std;

#define int long long

int inf = 1ll<<60;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int dp[200010];

int32_t main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	for(int j=0; j<=n; j++){
		dp[j] = -inf;
	}

	//max health such that
	//processed till i
	//potions consumed = j
	dp[0] = 0;
	int curind = 0;
	if(arr[0] >= 0){
		dp[1] = arr[0];
		curind = 1;
	}

	for(int i=1; i<n; i++){
		for(int j=n; j>0; j--){
			dp[j] = max(dp[j-1]+arr[i], dp[j]);
		}
	}

	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<=n; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	int ans = -1;
	for(int i=0; i<=n; i++){
		if(dp[i] >= 0){
			ans = i;
		}
	}

	cout << ans << "\n";

}
