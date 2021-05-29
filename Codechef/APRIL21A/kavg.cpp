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
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> arr(n+1, vector<int>(m+1));
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				cin >> arr[i][j];

		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				arr[i][j] += arr[i][j-1];

		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				arr[j][i] += arr[j-1][i];

		int ans1 = 0, ans2 = 0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				int s = 0, e = min(n-i, m-j), bans = -1;
				while(s <= e){
					int x = (s+e)/2;
					int a = arr[i+x][j+x] - arr[i-1][j+x];
					int b = arr[i+x][j-1] - arr[i-1][j-1];
					if(a-b >= k*(x+1)*(x+1)){
						bans = x;
						e = x-1;
					}
					else{
						s = x+1;
					}
				}
				if(bans != -1){
					ans1 += min(n-i, m-j) - bans + 1;
				}
			}
		}
		cout << ans1 << "\n";
	}
}
