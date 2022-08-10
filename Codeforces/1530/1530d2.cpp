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


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr(n);
		set<int> remaining;
		set<int> useless;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			arr[i]--;
			remaining.insert(arr[i]);
		}

		for(int i=0; i<n; i++){
			if(remaining.find(i) == remaining.end()){
				useless.insert(i);
			}
		}

		print(remaining);
		print(useless);

		vector<int> ans(n);
		for(int i=0; i<n; i++){
			if(remaining.find(arr[i]) != remaining.end()){
				ans[i] = arr[i];
				remaining.erase(arr[i]);
			}
			else{
				ans[i] = *useless.begin();
				useless.erase(useless.begin());
			}
		}

		print(ans);
	}


}

//Read the stuff at the top