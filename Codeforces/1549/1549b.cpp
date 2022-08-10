#include <bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


bool dfs(int a, int L, vector<vector<int>>& g, vector<int>& btoa, vector<int>& A, vector<int>& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vector<int>>& g, vector<int>& btoa) {
	int res = 0;
	vector<int> A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(A.begin(), A.end(), 0);
		fill(B.begin(), B.end(), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		for(int a=0; a<g.size(); a++) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		for(int a=0; a<g.size(); a++)
			res += dfs(a, 0, g, btoa, A, B);
	}
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr1(n), arr2(n);
		string s1, s2;
		cin >> s1 >> s2;
		for(int i=0; i<n; i++){
			arr1[i] = s1[i]-'0';
		}
		for(int i=0; i<n; i++){
			arr2[i] = s2[i]-'0';
		}


		vector<vector<int>> graph(n);

		for(int i=1; i<n-1; i++){
			if(arr2[i]&arr1[i-1])
				graph[i].push_back(i-1);
			if(arr2[i]&arr1[i+1])
				graph[i].push_back(i+1);
		}

		if(arr2[0]&arr1[1])
			graph[0].push_back(1);
		if(arr2[n-1]&arr1[n-2])
			graph[n-1].push_back(n-2);

		for(int i=0; i<n; i++){
			if(arr2[i] == 1 && arr1[i] == 0)
				graph[i].push_back(i);
		}

		// for(auto x: graph){
		// 	print(x);
		// }

		vector<int> ans(n, -1);
		hopcroftKarp(graph, ans);

		int res = 0;
		for(auto x: ans){
			if(x != -1)
				res++;
		}
		cout << res << "\n";
	}
}

