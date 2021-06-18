#include <bits/stdc++.h>
using namespace std;

#define MAX 500050

typedef long long ll;


vector<int> subtreeSize(MAX), depth(MAX);
vector<ll> totalDist(MAX), rerootDist(MAX), mp(MAX);
vector<vector<int>> stable(MAX, vector<int>(20, 0));
int n, q;

void dfs(vector<int> tree[], int v, int p, int d){
	subtreeSize[v] = 1;
	totalDist[v] = 0;
	depth[v] = d;
	stable[v][0] = p;
	for(int i=1; i<20; i++){
		if(stable[v][i-1] != -1 && stable[stable[v][i-1]][i-1] != -1)
			stable[v][i] = stable[stable[v][i-1]][i-1];
		else
			stable[v][i] = -1;
	}

	for(auto x: tree[v]){
		if(x != p){
			dfs(tree, x, v, d+1);
			subtreeSize[v] += subtreeSize[x];
			totalDist[v] += totalDist[x] + subtreeSize[x];
		}
	}
}

void dfs2(vector<int> tree[], int v, int p, ll val){
	rerootDist[v] = val;
	for(auto x: tree[v]){
		if(x != p){
			dfs2(tree, x, v, val+n-2*subtreeSize[x]);
			mp[x] = val-(totalDist[x]+subtreeSize[x]);
		}
	}
}

int LCA(int a, int b){
	if(depth[b] > depth[a]){
		swap(a, b);
	}

	//a is now at greater depth
	for(int i=19; i>=0; i--){
		if(stable[a][i] != -1 && depth[stable[a][i]] >= depth[b])
			a = stable[a][i];
	}

	if(a == b){
		return a;
	}

	//a and b now at same depth
	for(int i=19; i>=0; i--){
		if(stable[a][i] != -1 && stable[b][i] != -1 && stable[a][i] != stable[b][i]){
			a = stable[a][i];
			b = stable[b][i];
		}
	}

	return stable[a][0];
}


//only works if a is in subtree of lca
int findDist(int a, int lca){
	return depth[a]-depth[lca];
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){

		cin >> n >> q;
		vector<int> tree[n];
		for(int i=0; i<n-1; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		dfs(tree, 0, -1, 0);
		dfs2(tree, 0, -1, totalDist[0]);

		while(q--){
			int a, b;
			cin >> a >> b;
			a--; b--;
			int lca = LCA(a, b);

			if(findDist(a, lca) < findDist(b, lca)){
				swap(a, b);
			}

			//a cant reach till lca
			int cutoffa = a;

			for(int i=19; i>=0; i--){
				int v = stable[cutoffa][i];
				if(v != -1 && depth[v] > depth[lca]){
					int dist1 = findDist(a, v);
					int dist2 = findDist(b, lca)+findDist(v, lca);

					if(dist1 < dist2)
						cutoffa = v;
				}
			}

			int atreeSize = subtreeSize[cutoffa];
			int btreeSize = n-atreeSize;
			
			int cutaadist = findDist(a, cutoffa) + 1;
			ll one = rerootDist[a] - (mp[cutoffa] + (ll)cutaadist*btreeSize); 
			
			int cutabdist = findDist(cutoffa, lca) + findDist(b, lca);
			ll two = rerootDist[b] - (totalDist[cutoffa] + (ll)cutabdist*atreeSize);
			
			cout << one + two << "\n";
		}
	}
}
