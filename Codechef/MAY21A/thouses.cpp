#include <bits/stdc++.h>
using namespace std;

#define int long long
 
#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int mod = 1000000007;

int solve(vector<int> tree[], int v, int p){
	vector<int> vals;
	for(auto x: tree[v]){
		if(x != p){
			int a = solve(tree, x, v);
			vals.push_back(a);
		}
	}

	sort(vals.begin(), vals.end(), greater<int>());

	int ans = 1;
	for(int i=0; i<vals.size(); i++){
		ans += vals[i]*(i+1);
	}

	return ans;
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		vector<int> tree[n];
		for(int i=0; i<n-1; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		int ans = solve(tree, 0, -1);
		cout << ans%mod * x % mod << "\n";
	}


}

