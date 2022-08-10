/*
THINGS TO DO
1) Check integer overflows
2) Check corner cases
3) Compile and run once on terminal
4) Code smart, not quick
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int fact[1000];
int mod = 1000000007;

//1st state is root
//2nd state is node
int stsize[500][500];
int stsizeprod[500];

void dfs(vector<int> tree[], int v, int p, int root){
	stsize[root][v] = 1;
	for(auto x: tree[v]){
		if(x != p){
			dfs(tree, x, v, root);
			stsize[root][v] += stsize[root][x];
		}
	}
}

void dfs2(vector<int> tree[], int v, int p, int root){
	stsizeprod[root] *= stsize[root][v];
	stsizeprod[root] %= mod;
	for(auto x: tree[v]){
		if(x != p){
			dfs2(tree, x, v, root);
		}
	}
}

// b > a
int solve(int a, int b, vector<int> tree[]){

}

int32_t main(){

	fact[0] = 1;
	for(int i=1; i<1000; i++)
		fact[i] = fact[i-1]*i % mod;


	int n;
	cin >> n;
	vector<int> tree[n];
	for(int i=0; i<n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	for(int i=0; i<n; i++){
		dfs(tree, i, -1, i);
	}
	for(int i=0; i<n; i++){
		dfs2(tree, i, -1, i);
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << stsize[i][j] << " ";
		}
		cout << "\n";
	}

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			solve(tree, i, j);
		}
	}


}

//Read the stuff at the top