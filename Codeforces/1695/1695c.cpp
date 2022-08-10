#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

#define MAX 1005

int n, m;
int arr[MAX][MAX];

bitset<MAX> dp[MAX][MAX];

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int arr[n][m];
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin >> arr[i][j];

		if((n+m-1) % 2){
			cout << "NO\n";
			continue;
		}

		for(int i=0; i<MAX; i++)
			dp[0][0][i] = 0;


		if(arr[0][0] == 1)
			dp[0][0][1] = 1;
		else
			dp[0][0][0] = 1;


		for(int i=1; i<n; i++){
			dp[i][0] = dp[i-1][0];
			if(arr[i][0] == 1)
				dp[i][0] <<= 1;
		}

		for(int i=1; i<m; i++){
			dp[0][i] = dp[0][i-1];
			if(arr[0][i] == 1)
				dp[0][i] <<= 1;
		}

		for(int i=1; i<n; i++){
			for(int j=1; j<m; j++){
				dp[i][j] = dp[i-1][j] | dp[i][j-1];
				if(arr[i][j] == 1)
					dp[i][j] <<= 1;
			}
		}

		// for(int i=0; i<n; i++){
		// 	for(int j=0; j<m; j++){
		// 		debug(i, j);
		// 		for(int k=0; k<4; k++)
		// 			cout << dp[i][j][k];
		// 		cout << "\n";
		// 	}
		// }

		if(dp[n-1][m-1][(n+m-1)/2])
			cout << "YES\n";
		else
			cout << "NO\n";

	}
}

