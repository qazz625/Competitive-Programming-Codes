#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int solve(vector<int> &arr){
	int n = arr.size();
	if(n == 0)
		return 0;

	vector<pair<int, int>> dp(n);

	if(arr[0]%2)
		dp[0].second = 1;
	else
		dp[0].first = 1;

	for(int i=1; i<n; i++){
		dp[i].first = dp[i-1].first;
		dp[i].second = dp[i-1].second;
		if(arr[i]%2){
			dp[i].second = dp[i-1].first+1;
		}
		else{
			dp[i].first = dp[i-1].second+1;
		}
	}
	return max(dp[n-1].first, dp[n-1].second);
	// print(arr);
	// print(dp);
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];

		vector<vector<int>> vp(n+5);

		for(int i=0; i<n; i++){
			cin >> arr[i];
			vp[arr[i]].push_back(i);
		}
		// print(vp);

		for(int i=1; i<=n; i++){
			int ans = solve(vp[i]);
			cout << ans << " ";
		}
		cout << "\n";
	}
}
