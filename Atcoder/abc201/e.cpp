#pragma GCC optimize ("trapv")

#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int mod = 1000000007;

int answer[200010][2][2];

void solve(vector<pair<int, int>> tree[], int v, int par, int bit){
	// debug(bit, v, par);
	vector<pair<int, int>> children;
	for(auto x: tree[v]){
		if(x.first != par){
			solve(tree, x.first, v, bit);
			if( (1ll<<bit)&x.second ){
				answer[v][0][0] += answer[x.first][1][0];
				answer[v][1][0] += answer[x.first][0][0]+1;
				children.push_back({answer[x.first][1][0], answer[x.first][0][0]+1});
			}
			else{
				answer[v][0][0] += answer[x.first][0][0]+1;
				answer[v][1][0] += answer[x.first][1][0];
				children.push_back({answer[x.first][0][0]+1, answer[x.first][1][0]});
			}
		}
	}

	if(children.size() <= 1)
		return;


	int n = children.size();
	vector<int> pref0(n), pref1(n), suff0(n), suff1(n);
	pref0[0] = children[0].first;
	pref1[0] = children[0].second;
	suff0[n-1] = children[n-1].first;
	suff1[n-1] = children[n-1].second;
	// print(pref0);
	// print(pref1);
	// print(suff0);
	// print(suff1);

	// cout << "\n";

	for(int i=1; i<n; i++){
		pref0[i] = pref0[i-1] + children[i].first;
		pref1[i] = pref1[i-1] + children[i].second;
	}
	for(int i=n-2; i>=0; i--){
		suff0[i] = suff0[i+1] + children[i].first;
		suff1[i] = suff1[i+1] + children[i].second;
	}

	// 	print(children);
	// print(pref0);
	// print(pref1);
	// print(suff0);
	// print(suff1);


	//for bit = 0
	answer[v][0][1] += children[0].first * suff0[1];
	answer[v][0][1] += children[0].second + suff1[1];
	for(int i=1; i<children.size()-1; i++){
		answer[v][0][1] += children[i].first * (pref0[i-1]+suff0[i+1]);
		answer[v][0][1] += children[i].second * (pref1[i-1]+suff1[i+1]);
	}
	answer[v][0][1] += children[n-1].first * suff0[n-2];
	answer[v][0][1] += children[n-1].second * suff1[n-2];	
	// debug(answer[v][0][1], v);
	answer[v][0][1] /= 2;


	//for bit = 1
	answer[v][1][1] += children[0].first * suff1[1];
	answer[v][1][1] += children[0].second * suff0[1];
	for(int i=1; i<children.size()-1; i++){
		answer[v][1][1] += children[i].first * (pref1[i-1]+suff1[i+1]);
		answer[v][1][1] += children[i].second * (pref0[i-1]+suff0[i+1]);
	}
	answer[v][1][1] += children[n-1].first * suff1[n-2];
	answer[v][1][1] += children[n-1].second * suff0[n-2];
	// debug(answer[v][1][1]);
	answer[v][1][1] /= 2;
	
}


int32_t main(){
	int n;
	cin >> n;
	vector<pair<int, int>> tree[n];
	for(int i=0; i<n-1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		tree[u].push_back({v, w});
		tree[v].push_back({u, w});
	}

	int ans = 0;

	for(int bit=0; bit<=60; bit++){
		// debug(bit);
		for(int i=0; i<200010; i++)
			for(int j=0; j<2; j++)
				for(int k=0; k<2; k++)
					answer[i][j][k] = 0;

		solve(tree, 0, -1, bit);
		// for(int i=0; i<n; i++){
		// 	debug(i);
		// 	for(int j=0; j<2; j++)
		// 		cout << answer[i][1][j] << " ";
		// 	cout << "\n";
		// }
		// cout << "\n";

		for(int i=0; i<n; i++){
			for(int j=0; j<2; j++){
				// debug(i, answer[i][1][j]);
				ans += ((1ll<<bit)%mod)*(answer[i][1][j]%mod);
				ans %= mod;
			}
		}
		// debug(ans);
	}
	debug(ans);
	// debug(ans%mod);


}

//Read the stuff at the top