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
using namespace __gnu_pbds; 

typedef tree<int, null_type, less<int>, rb_tree_tag,
 tree_order_statistics_node_update> 
    pbds_set; 
    
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
   
#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

void dfs(vector<int> tree[], int v, int p, vector<int> &depths, int depth){
	depths[v] = depth;
	for(auto x: tree[v]){
		if(x != p)
			dfs(tree, x, v, depths, depth+1);
	}
}

int32_t main(){
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

	while(true){
		int q;
		cin >> q;
		q--;
		vector<int> depths(n);
		dfs(tree, q, -1, depths, 0);
		for(auto x: depths){
			cout << x << " ";
		}
		cout << endl;
	}


}

//Read the stuff at the top