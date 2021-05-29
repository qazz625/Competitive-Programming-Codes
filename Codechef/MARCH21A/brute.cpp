#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

void bfs(int s, int dist[],vector<int> graph[]){
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(q.size() != 0){
		int fr = q.front();
		for(auto x: graph[fr]){
			if(dist[x] == 1e7)
				q.push(x);
			dist[x] = min(dist[x], dist[fr]+1);
		}
		q.pop();
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		x--; y--;
		vector<int> graph[n];

		for(int i=0; i<m; i++){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a--; b--; c--; d--;
			for(int j=a; j<=b; j++){
				for(int k=c; k<=d; k++){
					graph[j].push_back(k);
				}
			}
		}

		int res[n];
		for(int i=0; i<n; i++)
			res[i] = 1e7;
		bfs(x, res, graph);
		if(res[y] == 1e7)
			cout << "-1\n";
		else
			cout << res[y] << "\n";
	}
}
