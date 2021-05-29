#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int t;
	t = 1;
	// cin >> t;
	while(t--){
		int n, m, k;
		// cin >> n >> m >> k;
		n = 500, m = 500, k = 1;
		vector<vector<int>> arr(n+1, vector<int>(m+1));
		// for(int i=1; i<=n; i++)
		// 	for(int j=1; j<=m; j++)
		// 		cin >> arr[i][j];

		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				arr[i][j] = i+j;

		// for(auto x: arr)
		// 	print(x);

		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++)
				arr[i][j] += arr[i][j-1];
		}

		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				arr[j][i] += arr[j-1][i];


		// for(auto x: arr)
		// 	print(x);

		int ans = 0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				for(int x=0; i+x<=n && j+x<=m; x++){
					int a = arr[i+x][j+x] - arr[i-1][j+x];
					int b = arr[i+x][j-1] - arr[i-1][j-1];
					if(a-b >= k*(x+1)*(x+1)){
						ans++;
					}
				}
			}
		}
		debug(ans);

		
	}


}

//Read the stuff at the top