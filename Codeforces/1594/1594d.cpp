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

void bfs(int source, int visited[], vector<pair<int, string>> arr[]){
	queue<int> q;
	q.push(s);

	
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<pair<int, string>> arr[n];

		for(int i=0; i<m; i++){
			int u, v;
			cin >> u >> v;
			string s;
			cin >> s;
			u--; v--;
			arr[u].push_back({v, s});
		}

		int visited[n] = {0};
		for(int i=0; i<n; i++){
			if(visited[i] == 0){
				bfs(i, visited, arr);
			}
		}
	}


}

//Read the stuff at the top