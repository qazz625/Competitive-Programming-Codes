#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int parents[100010];
int n;

void dfs(set<int> tree[], int p, int v, int &maxdepth, int depth, int &node){
	if(depth > maxdepth){
		node = v;
		maxdepth = depth;
	}
	parents[v] = p;

	for(auto x: tree[v]){
		if(x != p){
			dfs(tree, v, x, maxdepth, depth+1, node);
		}
	}
}

void find_dia(set<int> tree[], int root, vector<int> &path){
	for(int i=0; i<n; i++)
		parents[i] = -1;

	int maxdepth = -1, node = -1;
	dfs(tree, -1, root, maxdepth, 0, node);
	int u = node;

	maxdepth = -1; node = -1;
	dfs(tree, -1, u, maxdepth, 0, node);
	int v = node;

	while(v != -1){
		path.push_back(v);
		v = parents[v];
	}
	reverse(path.begin(), path.end());
}


pair<int, int> solve(set<int> tree[], int root, vector<vector<int>> &ans){
	vector<int> path;
	find_dia(tree, root, path);
	// print(path);

	if(path.size() == 1){
		return {path[0], path[0]};
	}

	vector<pair<int, int>> nextsolve;
	//parent, child

	// for(int i=0; i<n; i++){
	// 	cout << i << ": ";
	// 	for(auto x: tree[i]){
	// 		cout << x << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";


	for(int i=1; i<path.size()-1; i++){
		vector<int> erasex, erasepath;
		for(auto x: tree[path[i]]){
			// debug(x, i);
			if(x != path[i+1] && x != path[i-1]){
				// debug(x, i, path[i]);
				tree[x].erase(path[i]);
				erasepath.push_back(x);
				nextsolve.push_back({path[i], x});
				// print(nextsolve);
			}
		}
		for(auto x: erasepath){
			tree[path[i]].erase(x);
		}
	}

	// print(path);

	// print(nextsolve);
	int prev = -1;
	for(auto x: nextsolve){
		// debug(prev);
		pair<int, int> nodes = solve(tree, x.second, ans);
		int firstnode = nodes.first;
		int lastnode = nodes.second;
		// print(nodes);
		if(prev == -1)
			ans.push_back({x.first, x.second, lastnode, path[0]});
		else
			ans.push_back({x.first, x.second, lastnode, prev});
		prev = firstnode;
	}
	return {path[0], path.back()};
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		cin >> n;
		set<int> tree[n];
		for(int i=0; i<n-1; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			tree[u].insert(v);
			tree[v].insert(u);
		}
		vector<vector<int>> ans;
		pair<int, int> nodes = solve(tree, 0, ans);

		cout << ans.size() << "\n";
		for(auto &x: ans){
			for(auto y: x){
				cout << y+1 << " ";
			}
			cout << "\n";
		}
	}
}

