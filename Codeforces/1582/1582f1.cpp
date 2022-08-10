
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int dp[100010][512];

int32_t main(){
	int n;
	cin >> n;
	int arr[n];

	for(int i=0; i<n; i++)
		cin >> arr[i];


	for(int i=0; i<100010; i++)
		for(int j=0; j<512; j++)
			dp[i][j] = 1000;


	dp[0][0] = -1;
	dp[0][arr[0]] = min(dp[0][arr[0]], arr[0]);

	for(int i=1; i<n; i++){
		// debug(i);
		for(int j=0; j<512; j++){
			dp[i][j] = dp[i-1][j];
		}
		// debug(i);

		for(int j=0; j<512; j++){
			if(arr[i] > dp[i-1][j^arr[i]]){
				dp[i][j] = min(dp[i][j], arr[i]);
			}
		}
	}

	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<8; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	vector<int> ans;
	for(int i=0; i<512; i++){
		if(dp[n-1][i] != 1000){
			ans.push_back(i);
		}
	}

	cout << ans.size() << "\n";
	for(auto x: ans){
		cout << x << " ";
	}
	cout << "\n";


}
