#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int isfib[200010];
int parents[200010];
int mark[200010];
int subtree[200010];
string ans = "YES";

void dfs(vector<int> tree[], int v, int p, int &poss, int tot){
	if(isfib[subtree[v]] == 1 && isfib[tot-subtree[v]] == 1){
		poss = v;
	}
	for(auto x: tree[v]){
		if(x != p && mark[x] == 0){
			dfs(tree, x, v, poss, tot);
		}
	}
}


void solve(vector<int> tree[], int root, int tot){
	// debug(root, tot);
	if(tot <= 3){
		return;
	}

	int poss = -1;

	dfs(tree, root, parents[root], poss, tot);

	if(poss == -1){
		ans = "NO";
		return;
	}

	int x = poss;
	if(x != 0) mark[parents[x]] = 1;
	solve(tree, x, subtree[x]);
	if(x != 0) mark[parents[x]] = 0;

	mark[x] = 1;
	{
		int temp = parents[x];
		while(temp != -1){
			subtree[temp] -= subtree[x];
			temp = parents[temp];
		}
	}
	solve(tree, root, tot-subtree[x]);
	mark[x] = 0;
	{
		int temp = parents[x];
		while(temp != -1){
			subtree[temp] += subtree[x];
			temp = parents[temp];
		}
	}
}

void calcsub(vector<int> tree[], int v, int p){
	subtree[v]++;
	for(auto x: tree[v]){
		if(x != p && mark[x] == 0){
			calcsub(tree, x, v);
			subtree[v] += subtree[x];
		}
	}
}



void findparents(vector<int> tree[], int v, int p){
	parents[v] = p;
	for(auto x: tree[v])
		if(x != p)
			findparents(tree, x, v);
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

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

	int a=1, b=1;
	isfib[1] = 1;
	for(;a<200010;){
		isfib[a] = 1;
		int c = a;
		a += b;
		b = c;
	}

	calcsub(tree, 0, -1);
	findparents(tree, 0, -1);

	if(isfib[n] == 0){
		cout << "NO\n";
		return 0;
	}

	solve(tree, 0, n);
	cout << ans << "\n";
}
