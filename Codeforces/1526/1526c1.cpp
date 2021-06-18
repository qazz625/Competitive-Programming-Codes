#include <bits/stdc++.h>
using namespace std;

#define int long long

int inf = 1ll<<60;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int dp[2010][2010];
int n;
void solve(int index, int arr[]){
	if(index == 0){
		dp[index][0] = 0;
		if(arr[0] >= 0)
			dp[index][1] = arr[0];
		return;
	}

	solve(index-1, arr);
	dp[index][0] = 0;
	for(int i=1; i<=n; i++){
		dp[index][i] = max(dp[index-1][i-1]+arr[index], dp[index-1][i]);
		if(dp[index][i] < 0)
			dp[index][i] = -inf;
	}
}

int32_t main(){
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	for(int i=0; i<n; i++)
		for(int j=0; j<=n; j++)
			dp[i][j] = -inf;

	solve(n-1, arr);


	int ans = -1;
	for(int i=0; i<=n; i++){
		if(dp[n-1][i] >= 0){
			ans = i;
		}
	}

	cout << ans << "\n";

}
