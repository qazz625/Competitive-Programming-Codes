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

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag,
 tree_order_statistics_node_update> 
    pbds_set; 
    
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
   
#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

bool compare(pair<int, int> a, pair<int, int> b){
	return a.first*b.second > b.first*a.second;
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> arr(n);
		int total = 0;
		for(int i=0; i<n; i++){
			cin >> arr[i].first;
			total += arr[i].first;
		}
		for(int i=0; i<n; i++){
			cin >> arr[i].second;
		}

		if(total < m){
			cout << "-1\n";
			continue;
		}

		sort(arr.begin(), arr.end(), compare);

		print(arr);

		int cur = 0, ind = 0, convlost = 0;
		while(cur < m){
			debug(cur, convlost);
			cur += arr[ind].first;
			convlost += arr[ind].second;
			ind++;
		}
		cout << convlost << "\n";
	}


}

//Read the stuff at the top