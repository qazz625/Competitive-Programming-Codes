#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int find_rep(int a, int parents[]){
	if(parents[a] != a){
		parents[a] = find_rep(parents[a], parents);
		return parents[a];
	}
	else
		return a;
	
}

void join(int a, int b, int parents[], int sizes[]){
	a = find_rep(a, parents);
	b = find_rep(b, parents);

	if(a == b)
		return;

	if(sizes[a] < sizes[b]){
		parents[a] = b;
		sizes[b] += sizes[a];
		find_rep(a, parents);
	}
	else{
		parents[b] = a;
		sizes[a] += sizes[b];
		find_rep(b, parents);
	}
}

int32_t main(){
	int n, m1, m2;
	cin >> n >> m1 >> m2;

	int parents1[n], sizes1[n];
	int parents2[n], sizes2[n];

	for(int i=0; i<n; i++){
		parents1[i] = i;
		parents2[i] = i;
		sizes1[i] = 1;
		sizes2[i] = 1;
	}

	for(int i=0; i<m1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		join(u, v, parents1, sizes1);
	}

	for(int i=0; i<m2; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		join(u, v, parents2, sizes2);
	}

	vector<pair<int, int>> ans;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int a = find_rep(i, parents1);
			int b = find_rep(j, parents1);
			int c = find_rep(i, parents2);
			int d = find_rep(j, parents2);

			if(a != b && c != d){
				ans.push_back({i, j});
				join(a, b, parents1, sizes1);
				join(c, d, parents2, sizes2);
			}
		}
	}

	cout << ans.size() << "\n";
	for(auto p: ans){
		cout << p.first+1 << " " << p.second+1 << "\n";
	}


}
