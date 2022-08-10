#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int mod = 1000000007;

pair<int, int> solve(int v, int parent[], vector<pair<int, int>> &prob, map<int, pair<int, int>> &solved){
	if(v == -1){
		solved[-1] = {1000000ll, 0ll};
		return {1000000, 0};
	}

	pair<int, int> a;
	if(solved.find(parent[v]) == solved.end()){
		pair<int, int> a = solve(parent[v], parent, prob, solved);
		pair<int, int> p;
		p.first = (a.first * prob[v].first + a.second * prob[v].second)/1000000;
		p.second = (1000000 - p.first);

		solved[v] = p;
		debug(v);
		print(p);
		return p;
	}
	else{
		return prob[];
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		int parent[n] = {0};
		parent[0] = -1;

		vector<pair<int, int>> prob(n);
		int p0;
		cin >> p0;

		prob[0].first = p0;
		prob[0].second = 1000000 - p0;
		for(int i=1; i<n; i++){
			cin >> parent[i] >> prob[i].first >> prob[i].second;
			parent[i]--;
		}

		while(q--){
			int u, v;
			cin >> u >> v;
			u--; v--;

			map<int, pair<int, int>> solved;
			pair<int, int> p1 = solve(v, parent, prob, solved);
			print(p1);
			pair<int, int> p2 = solve(u, parent, prob, solved);
			print(p2);
		}
	}


}

//Read the stuff at the top