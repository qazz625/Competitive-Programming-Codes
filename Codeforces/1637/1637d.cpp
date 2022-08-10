#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int dp[110][10010];
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n], b[n];
		int sqtot = 0, tot = 0;
		for(int i=0; i<n; i++){
			cin >> a[i];
			sqtot += a[i]*a[i];
			tot += a[i];
		}
		for(int i=0; i<n; i++){
			cin >> b[i];
			sqtot += b[i]*b[i];
			tot += b[i];
		}

		for(int i=0; i<=n; i++){
			for(int j=0; j<10010; j++){
				dp[i][j] = 0;
			}
		}

		if(n == 1){
			cout << "0\n";
			continue;
		}


		dp[0][a[0]] = 1;
		dp[0][b[0]] = 1;

		for(int i=0; i<n-1; i++){
			for(int j=0; j<10010; j++){
				if(dp[i][j] == 1){
					if(j+a[i+1] < 10010)
						dp[i+1][j+a[i+1]] = 1;
					if(j+b[i+1] < 10010)
						dp[i+1][j+b[i+1]] = 1;
				}
			}
		}

		// for(int i=0; i<n; i++){
		// 	for(int j=0; j<25; j++){
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }

		int ans = 1ll<<60;
		for(int i=0; i<10010; i++){
			if(dp[n-1][i] == 1){
				int suma = i;
				int sumb = tot-i;
				ans = min(ans, (n-2)*sqtot + suma*suma + sumb*sumb);
			}
		}

		cout << ans << "\n";

	}
}

