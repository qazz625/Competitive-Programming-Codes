#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		int oriarr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
			oriarr[i] = arr[i];
		}

		int dp[n] = {0};

		dp[0] = arr[0]-1;
		dp[1] = dp[0]+arr[1]-1;
		for(int i=2; i<n; i++){
			for(int j=i-2; j>=0; j--){
				if(oriarr[j] >= i-j){
					arr[i]--;
				}
			}
			debug(i, arr[i]);
			dp[i] = dp[i-1] + max(arr[i]-1, 0ll);
		}
		print(dp, n);
		cout << dp[n-1] << "\n";
	}
}
