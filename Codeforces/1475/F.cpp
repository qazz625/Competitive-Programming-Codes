#include <bits/stdc++.h>
using namespace std;

int n;

void bfs(vector<pair<int, int>> graph[], int colour[], int start){
	queue<int> q;
	q.push(start);
	colour[start] = 0;

	while(q.size() != 0){
		int temp = q.front();
		for(int i=0; i<n; i++){
			if(colour[graph[temp][i].first] == -1){
				colour[graph[temp][i].first] = colour[temp]^graph[temp][i].second;
				q.push(graph[temp][i].first);
			}
		}
		q.pop();
	}
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		string mat[n];
		for(int i=0; i<n; i++)
			cin >> mat[i];

		string goal[n];
		for(int i=0; i<n; i++)
			cin >> goal[i];

		vector<pair<int, int>> graph[2*n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(mat[i][j] != goal[i][j]){
					graph[i].push_back({n+j, 1});
					graph[n+j].push_back({i, 1});
				}
				else{
					graph[i].push_back({n+j, 0});
					graph[n+j].push_back({i, 0});
				}
			}
		}

		int colour[2*n];
		for(int i=0; i<2*n; i++)
			colour[i] = -1;

		bfs(graph, colour, 0);

		string ans = "YES";
		for(int i=0; i<n; i++)
			for(auto x: graph[i])
				if(colour[i] != colour[x.first]^x.second)
					ans = "NO";

		cout << ans << "\n";
	}
}
