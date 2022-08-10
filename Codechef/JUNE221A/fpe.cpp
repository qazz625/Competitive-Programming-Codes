#include <bits/stdc++.h>
using namespace std;   

#define int long long 

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int arr[400000];
int totsum[400000];
int ans = 0;

void dfs1(vector<int> tree[], int v, int p, vector<int> nodegcds[], int gcds[]){
	vector<int> newnode;
	int g = arr[v];
	for(auto x: tree[v]){
		if(x != p){
			dfs1(tree, x, v, nodegcds, gcds);
			g = __gcd(g, gcds[x]);
			newnode.push_back(x);
		}
	}
	tree[v] = newnode;
	gcds[v] = g;

	if(newnode.size() != 0){
		int n = tree[v].size();
		int pref[n], suff[n];
		pref[0] = gcds[tree[v][0]];
		suff[n-1] = gcds[tree[v][n-1]];
		for(int i=1; i<n; i++){
			pref[i] = pref[i-1] + gcds[tree[v][i]];
		}
		for(int i=n-2; i>=0; i--){
			suff[i] = suff[i+1] + gcds[tree[v][i]];
		}
		totsum[v] = pref[n-1];

		vector<int> cur(n);
		if(n >= 2){
			cur[0] = suff[1];
			cur[n-1] = pref[n-2];

		}
		else{
			cur[0] = 0;
		}

		for(int i=1; i<n-1; i++){
			cur[i] = pref[i-1] + suff[i+1];
		}
		nodegcds[v] = cur;
	}
}

void dfs2(vector<int> tree[], int v, vector<int> nodegcds[], int g){
	ans = max(ans, g+totsum[v]);
	for(int i=0; i<tree[v].size(); i++){
		dfs2(tree, tree[v][i], nodegcds, g + nodegcds[v][i]);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ans = 0;
		int n;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			totsum[i] = 0;
		}

		vector<int> tree[n];
		for(int i=0; i<n-1; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		vector<int> nodegcds[n];
		int gcds[n];
		dfs1(tree, 0, -1, nodegcds, gcds);

		dfs2(tree, 0, nodegcds, 0);
		cout << ans << "\n";
	}
}
