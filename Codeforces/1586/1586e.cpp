#include <bits/stdc++.h> 
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n, m;

vector<int> bfs(vector<int> graph[], int a, int b){
	vector<int> prev(n, -1);
	queue<int> q;
	q.push(a);
	prev[a] = -2;

	while(q.size() != 0){
		int fr = q.front();
		for(auto x: graph[fr]){
			if(prev[x] == -1){
				prev[x] = fr;
				q.push(x);
			}
		}
		q.pop();
	}
	return prev;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	vector<int> graph1[n];
	map<pair<int, int>, int> edges;
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		edges[{x, y}] = 0;
		graph1[x].push_back(y);
		graph1[y].push_back(x);
	}


	vector<int> graph2[n];
	int q;
	cin >> q;
	vector<pair<int, int>> query;
	while(q--){
		int u, v;
		cin >> u >> v;
		u--; v--;
		query.push_back({u, v});
		graph2[u].push_back(v);
		graph2[v].push_back(u);
	}

	int odd = 0;
	for(int i=0; i<n; i++){
		if(graph2[i].size()%2 == 1)
			odd++;
	}

	if(odd != 0){
		cout << "NO\n";
		cout << odd/2 << "\n";
		return 0;
	}

	// for(int i=0; i<n; i++)
	// 	print(graph1[i]);

	vector<vector<int>> ans;

	for(int i=0; i<(int)query.size()-1; i++){
		vector<int> prevs = bfs(graph1, query[i].first, query[i].second);
		vector<int> cur = {query[i].second};
		while(cur.back() != -2)
			cur.push_back(prevs[cur.back()]);

		cur.pop_back();
		reverse(cur.begin(), cur.end());

		// print(prevs);
		// debug("AA");
		// print(cur);
		ans.push_back(cur);

		for(int i=0; i<(int)cur.size()-1; i++){
			edges[{cur[i], cur[i+1]}] ^= 1;
		}
	}

	// for(auto x: edges){
	// 	if(x.second == 1){
	// 		print(x.first);
	// 	}
	// }

	vector<int> graph3[n];
	for(auto x: edges){
		if(x.second == 1){
			graph3[x.first.first].push_back(x.first.second);
			graph3[x.first.second].push_back(x.first.first);
		}
	}

	vector<int> prevs = bfs(graph3, query.back().first, query.back().second);
	// print(prevs);

	vector<int> cur = {query.back().second};
	while(cur.back() != -2)
		cur.push_back(prevs[cur.back()]);

	cur.pop_back();
	reverse(cur.begin(), cur.end());

	// print(cur);
	ans.push_back(cur);

	// for(auto x: ans)
	// 	print(x);

	cout << "YES\n";
	for(auto x: ans){
		cout << x.size() << "\n";
		for(auto y: x){
			cout << y+1 << " ";
		}
		cout << "\n";
	}
}

