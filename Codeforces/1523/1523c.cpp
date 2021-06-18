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

int n;

void solve(string ans[], string &prev, vector<int> &arr, int l, int r){
	if(l > r){
		return;
	}

	map<int, int> mp;
	for(int i=r; i>=l; i--){
		mp[arr[i]] = i;
	}

	print(arr);
	print(mp);
	for(auto x: mp){
		string append = to_string(x.first);
		ans[x.second] = prev + append;
	}
	debug(l, r);

	for(int i=0; i<n; i++){
		debug(ans[i]);
	}

	int prevind = -1;
	for(auto x: mp){
		if(prevind != -1){
			solve(ans, ans[prevind], arr, prevind+1, x.second-1);
		}
		prevind = x.second;
	}
	solve(ans, ans[prevind], arr, prevind+1, r);
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		string ans[n];

		vector<int> arr(n);
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		string prev;
		solve(ans, prev, arr, 0, n-1);

		// for(int i=0; i<n; i++){
		// 	debug(ans[i]);
		// }
	}


}

//Read the stuff at the top