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
	#include "../../debug.cpp"
#endif


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		map<int, int> mp;
		for(int i=0; i<2*n; i++){
			cin >> arr[i];
			mp[arr[i]]++;
		}

		string ans = "YES";
		for(auto x: mp){
			if(x.second != 2 || x.first%2 == 1){
				ans = "NO";
			}
		}

		vector<int> v;
		for(auto x: mp)
			v.push_back(x.first);


		if(v[0] < n*n + n)
			ans = "NO";

		print(v);
		int prev = 0;
		for(int i=1; i<v.size(); i++){
			if(v[i] - v[i-1] - prev < 2*n)
				ans = "NO";
			prev = v[i]-v[i-1];
		}
		cout << ans << "\n";
	}
}

//Read the stuff at the top