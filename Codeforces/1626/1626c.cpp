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
		int karr[n], harr[n];

		for(int i=0; i<n; i++)
			cin >> karr[i];

		for(int i=0; i<n; i++)
			cin >> harr[i];

		vector<int> dp(n, 1ll<<60);

		dp[0] = harr[0]*(harr[0]+1)/2;


		for(int i=1; i<n; i++){
			int minpoint = karr[i]-harr[i]+1;
			for(int j=i-1; j>=0; j--){
				if(minpoint > karr[j]){
					int num = karr[i] - minpoint+1;
					dp[i] = min(dp[i], dp[j] + num*(num+1)/2);
				}
				minpoint = min(minpoint, karr[j]-harr[j]+1);
			}
			int num = karr[i] - minpoint+1;
			dp[i] = min(dp[i], num*(num+1)/2);
		}

		cout << dp[n-1] << "\n";

		// print(dp);
	}
}

