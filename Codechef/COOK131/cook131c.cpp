#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int dp[1010][1010];
int pref[1010][1010];

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int freq[1010];
		for(int i=0; i<1010; i++)
			freq[i] = -1;

		int n, k;
		cin >> n >> k;
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
			freq[arr[i]] = -1;
		}

		int prevnum[n] = {0};
		for(int i=0; i<n; i++){
			prevnum[i] = freq[arr[i]];
			freq[arr[i]] = i;
		}

		for(int i=0; i<1010; i++){
			for(int j=0; j<1010; j++){
				dp[i][j] = 0;
				pref[i][j] = 0;
			}
		}

		dp[0][0] = 1;
		pref[0][0] = 1;



		for(int i=1; i<n; i++){

			dp[i][0] = 1;
			pref[i][0] = max(pref[i-1][0], dp[i][0]);

			//selected same before
			for(int j=0; j<=k; j++){
				if(prevnum[i] != -1){
					dp[i][j] = max(dp[i][j], dp[prevnum[i]][j]+1);
					pref[i][j] = max(pref[i-1][j], dp[i][j]);
				}
			}

			//selected adjacent before
			if(prevnum[i] != i-1){
				for(int j=1; j<=k; j++){
					dp[i][j] = max(dp[i][j], pref[i-1][j-1]+1);
					pref[i][j] = max(pref[i-1][j], dp[i][j]);
				}
			}
		}

		int ans = 0;
		for(int j=0; j<n; j++){
			for(int i=0; i<=k; i++){
				ans = max(ans, dp[j][i]);
			}
		}
		
		cout << ans << "\n";
	}
}