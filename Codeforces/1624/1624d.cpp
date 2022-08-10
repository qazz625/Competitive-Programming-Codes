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

int n, k;
string s;

int check(vector<int> arr, int val){
	for(int i=0; i<k; i++){

	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		cin >> s;

		vector<int> arr(26);

		for(int i=0; i<n; i++){
			arr[s[i]-'a']++;
		}


		int st = 1, e = 200000, ans = -1;
		while(st <= e){
			int mid = (st+e)/2;

			int c = check(arr, mid);
		}
	}


}

//Read the stuff at the top