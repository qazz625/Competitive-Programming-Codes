#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int inf = 1<<30;

int dp[5010][5010];
int pref[5010][5010];

int32_t main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	int ind = 0;
	while(ind != n && arr[ind] == 0)
		ind++;

	if(ind == n){
		cout << "0\n";
		return 0;
	}

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			dp[i][j] = inf;

	// debug(ind);


	for(int i=0; i<n; i++){
		if(arr[i] == 0){
			dp[ind][i] = abs(i-ind);
		}
	}
	pref[ind][0] = dp[ind][0];
	for(int i=1; i<n; i++)
		pref[ind][i] = min(dp[ind][i], pref[ind][i-1]);

	int prev = ind;
	for(int i=ind+1; i<n; i++){
		if(arr[i] == 0)
			continue;

		for(int j=1; j<n; j++){
			if(arr[j] == 0){
				dp[i][j] = min(dp[i][j], pref[prev][j-1] + abs(i-j));
			}
		}
		pref[i][0] = dp[i][0];
		for(int j=1; j<n; j++)
			pref[i][j] = min(dp[i][j], pref[i][j-1]);

		prev = i;
	}

	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<n; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << pref[prev][n-1] << "\n";
}

