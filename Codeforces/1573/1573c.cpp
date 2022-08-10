#include <bits/stdc++.h> 
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int iscycle = 0;
int n;
void find_cycle(vector<int> graph[], int visited[], int curset[], int v){
	visited[v] = 1;
	curset[v] = 1;
	for(auto x: graph[v]){
		if(curset[x] == 1){
			iscycle = 1;
			break;
		}
		if(iscycle == 0 && visited[x] == 0){
			find_cycle(graph, visited, curset, x);
		}
	}
	curset[v] = 0;
}

vector<int> bfs(vector<int> &sources, vector<int> graph[], int visited[]){
	queue<int> q;
	vector<int> dist(n, 0);
	print(sources);
	for(auto x: sources){
		q.push(x);
		visited[x] = 1;
		dist[x] = 1;
	}

	debug("AA");

	vector<int> add(n, 0);
	for(int i=0; i<n; i++){
		// debug(i);
		// print(graph[i]);
		for(auto x: graph[i]){
			if(i > x)
				add[x] = 1;
		}
	}

	// print(add);

	while(q.size() != 0){
		int fr = q.front();
		for(auto x: graph[fr]){
			if(visited[x] == 0){
				if(i < x){
					dis
				}
				dist[x] = max(dist[x], add[x]+dist[fr]);
				visited[x] = 1;
				q.push(x);
			}
		}
		q.pop();
	}

	return dist;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){

		iscycle = 0;

		cin >> n;
		vector<int> graph[n];
		vector<int> sources;
		for(int i=0; i<n; i++){
			int num;
			cin >> num;
			if(num == 0)
				sources.push_back(i);
			while(num--){
				int x;
				cin >> x;
				x--;
				graph[x].push_back(i);
			}
		}


		int visited[n] = {0};
		int curset[n] = {0};
		for(int i=0; i<n; i++){
			if(visited[i] == 0){
				find_cycle(graph, visited, curset, 0);
			}
		}

		if(iscycle == 1){
			cout << "-1\n";
			continue;
		}


		int visited2[n] = {0};
		vector<int> dist = bfs(sources, graph, visited2);
		print(dist);

		int ans = -1;
		for(auto x: dist){
			ans = max(ans, x);
		}

		cout << ans << "\n";
	}


}

//Read the stuff at the top