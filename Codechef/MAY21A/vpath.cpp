#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod = 1000000007;

int dp[500010][2];
//0 for straigth chain
//1 for bent chain

void solve(vector<int> tree[], int v, int p){
	for(auto x: tree[v]){
		if(x != p)
			solve(tree, x, v);
	}

	int a = 0, b = 0;
	for(auto x: tree[v]){
		dp[v][0] += 2*dp[x][0];
		a += dp[x][0];
		b += dp[x][0]*dp[x][0];
		b %= mod;
		a %= mod;
	}
	dp[v][0]++;

	dp[v][0] %= mod;

	a = a*a % mod;

	dp[v][1] = ((a-b)%mod + mod)%mod;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> tree[n];
		for(int i=0; i<n-1; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<2; j++)
				dp[i][j] = 0;
		}

		solve(tree, 0, -1);

		int ans = dp[0][0];
		for(int i=0; i<n; i++){
			ans += dp[i][1];
		}

		cout << ans%mod << "\n";
	}
}

