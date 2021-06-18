/*
Handle k = 1, k = n, k = n-1 seperately.
Either select k elements with xor max or (n-k) elements with xor totxor(n)^max
hence select at most k/2 elements
*/


#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

pair<int, int> dp[256][256][256];
int32_t main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;


		for(int i=0; i<n; i++)
			for(int j=0; j<k; j++)
				for(int x=0; x<256; x++)
					dp[i][j][k] = {0, 0};

		dp[1][0][0] = {1, -1};
		dp[1][1][1] = {1, 1};

		for(int i=2; i<=n; i++){
			dp[i][0][0] = {1, -1};
			for(int j=1; j<=k; j++){
				for(int x=0; x<256; x++){
					//select current element
					if(dp[i-1][j-1][x].first == 1)
						dp[i][j][x^i] = {1, 1};

					//dont select current element
					if(dp[i-1][j][x].first == 1)
						dp[i][j][x] = {1, -1};
				}
			}
		}

		// for(int i=0; i<=k; i++){
		// 	for(int j=0; j<16; j++){
		// 		cout << dp[1][i][j].first << " ";
		// 	}
		// 	cout << "\n";
		// }

		int ans = -1;
		for(int i=0; i<256; i++){
			if(dp[n][k][i].first == 1){
				ans = i;
			}
		}

		int orians = ans;
		
		vector<int> res;
		int ind = n;
		while(ind != 0){
			if(dp[ind][k][ans].second == 1){
				ans ^= ind;
				k--;
				res.push_back(ind);
			}
			ind--;
		}

		debug(orians);
		for(auto x: res)
			cout << x << " ";
		cout << "\n";
	}
}

