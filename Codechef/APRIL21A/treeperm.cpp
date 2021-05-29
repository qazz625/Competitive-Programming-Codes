#include <bits/stdc++.h>
using namespace std;

int original[100010], final[100010], parents[100010];
int done[100010], nextdesc[100010];
long long mod = 1000000007;


void dfs(vector<int> tree[], int v, int p, vector<int> &leaves){
	parents[v] = p;
	for(auto x: tree[v])
		if(x != p)
			dfs(tree, x, v, leaves);
	if(tree[v].size() == 1 && v != 0)
		leaves.push_back(v);
}


//optimize this
void go_up(int v, set<int> tree[], vector<int> &leaves){
	multiset<int> current, expected;
	vector<int> indices;
	while(v != -1 && done[v] == 0){
		indices.push_back(v);
		if(original[v] != final[v]){
			auto itr2 = current.find(final[v]);
			auto itr3 = expected.find(original[v]);
			if(itr3 != expected.end())
				expected.erase(itr3);
			else
				current.insert(original[v]);
			if(itr2 != current.end())
				current.erase(itr2);
			else
				expected.insert(final[v]);
		}
		
		if(current.size() == 0 && expected.size() == 0)
			break;
		v = parents[v];
	}

	if(current == expected){
		for(auto x: indices)
			done[x] = 1;
		nextdesc[indices[0]] = -1;
		for(int i=1; i<indices.size(); i++){
			nextdesc[indices[i]] = indices[i-1];
		}
	}

	int last = indices.back();
	if(last != 0){
		tree[parents[last]].erase(last);
		if(parents[last] != 0 && tree[parents[last]].size() == 1)
			leaves.push_back(parents[last]);
		else if(parents[last] == 0 && tree[0].size() == 0)
			leaves.push_back(0);
	}
}

void solve(vector<int> tree[], long long dp[], int v){
	int start = v;
	long long prod = 1;
	while(nextdesc[v] != -1){
		for(auto x: tree[v]){
			if(x != nextdesc[v] && x != parents[v]){
				solve(tree, dp, x);
				prod *= dp[x];
				prod %= mod;
			}
		}
		v = nextdesc[v];
	}
	for(auto x: tree[v]){
		if(x != parents[v]){
			solve(tree, dp, x);
			prod *= dp[x];
			prod %= mod;
		}
	}

	dp[start] = prod;

	for(auto x: tree[v]){
		if(x != parents[v]){
			dp[start] += prod;
		}
	}
	dp[start] %= mod;

}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++){

		int n, s;
		cin >> n >> s;

		for(int i=0; i<n; i++){
			done[i] = 0;
		}

		vector<int> tree[n];
		for(int i=0; i<n-1; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}


		for(int i=0; i<n; i++)
			cin >> original[i];

		for(int i=0; i<n; i++)
			cin >> final[i];

		if(n == 1){
			if(original[0] == final[0])
				cout << "1\n";
			else
				cout << "0\n";
			continue;
		}
		
		set<int> tree2[n];
		for(int i=0; i<n; i++){
			for(auto x: tree[i])
				tree2[i].insert(x);
		}

		vector<int> leaves;
		dfs(tree, 0, -1, leaves);

		int flag = 0;
		for(int i=0; i<leaves.size(); i++){
			go_up(leaves[i], tree2, leaves);
			if(done[leaves[i]] == 0){
				flag = 1;
				break;
			}

		}

		for(int i=0; i<n; i++){
			if(done[i] == 0)
				flag = 1;
		}

		if(flag == 1){
			cout << "0\n";
			continue;
		}
		else if(s == 1){
			cout << "1\n";
			continue;
		}

		long long dp[n]={0};

		solve(tree, dp, 0);
		cout << dp[0] << "\n";
	}
}
