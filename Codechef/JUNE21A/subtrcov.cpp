#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

#define MAX 4000010

int maxdepth = -1;
int farthest = -1;
void dfs(vector<int> tree[], int v, int p, int depth){
	if(depth >maxdepth){
		maxdepth = depth;
		farthest = v;
	}

	for(auto x: tree[v]){
		if(x != p){
			dfs(tree, x, v, depth+1);
		}
	}
}

vector<int> parent(MAX);

void dfs2(vector<int> tree[], int v, int p, int depth, vector<pair<int, int>> &leaves){

	parent[v] = p;
	if(p != -1 && tree[v].size() == 1){
		leaves.push_back({depth, v});
	}
	for(auto x: tree[v]){
		if(x != p){
			dfs2(tree, x, v, depth+1, leaves);
		}
	}
}


vector<pair<int, int>> updateRange(MAX);

void dfs3(vector<int> tree[], int v, int p, map<int, int> &mp){
	int l = 1000000, r = -1;
	for(auto x: tree[v]){
		if(x != p){
			dfs3(tree, x, v, mp);
			l = min(l, updateRange[x].first);
			r = max(r, updateRange[x].second);
		}
	}

	if(p != -1 && tree[v].size() == 1){
		updateRange[v].first = mp[v];
		updateRange[v].second = mp[v];
	}
	else{
		updateRange[v].first = l;
		updateRange[v].second = r;
	}
}


vector<pair<int, int>> buildSegTree(vector<pair<int, int>> &arr){
	while((1<<30)%arr.size() != 0)
		arr.push_back({-1, -1});

	vector<pair<int, int>> segtree(2*arr.size());
	for(int i=0; i<arr.size(); i++)
		segtree[i+arr.size()] = arr[i];

	for(int i=segtree.size()-1; i!=1; i-=2)
		segtree[i/2] = max(segtree[i], segtree[i-1]);
	
	return segtree;
}

void update(vector<pair<int, int>> &segtree, int l, int r, int x, int y, int ind, int val,
	vector<int> &lazytree){
	if(l > y || r < x){
		return;
	}
	else if(x >= l && y <= r){
		lazytree[ind] += val;
	}
	else{
		int mid = (x+y)/2;
		lazytree[2*ind] += lazytree[ind];
		lazytree[2*ind+1] += lazytree[ind];
		lazytree[ind] = 0;
		update(segtree, l, r, x, mid, 2*ind, val, lazytree);
		update(segtree, l, r, mid+1, y, 2*ind+1, val, lazytree);

		pair<int, int> p1 = {segtree[2*ind].first+lazytree[2*ind], segtree[2*ind].second};
		pair<int, int> p2 = {segtree[2*ind+1].first+lazytree[2*ind+1], segtree[2*ind+1].second};
		segtree[ind] = max(p1, p2);
	}
}




int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){

		maxdepth = -1;
		farthest = -1;
		updateRange.clear(); parent.clear();

		int n, k;
		cin >> n >> k;
		updateRange.resize(n); parent.resize(n);

		vector<int> tree[n];
		for(int i=0; i<n-1; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		vector<pair<int, int>> leaves;

		dfs(tree, 0, -1, 0);

		int root = farthest;

		dfs2(tree, root, -1, 0, leaves);

		map<int, int> mp;
		for(int i=0; i<leaves.size(); i++){
			mp[leaves[i].second] = i;
		}

		dfs3(tree, root, -1, mp);

		vector<pair<int, int>> segtree = buildSegTree(leaves);
		vector<int> lazytree(segtree.size());

		int setsize = 1;
		int done[n] = {0};
		done[root] = 1;
		k--;
		update(segtree, 0, leaves.size()-1, 0, leaves.size()-1, 1, -1, lazytree);
		while(k > 0){
			pair<int, int> p = segtree[1];
			int cur = p.second;
			while(done[cur] == 0){
				pair<int, int> range = updateRange[cur];
				update(segtree, range.first, range.second, 0, leaves.size()-1, 1, -1, lazytree);
				done[cur] = 1;
				cur = parent[cur];
				k--;
			}
			setsize++;
			
		}
		cout << setsize << "\n";
	}
}

