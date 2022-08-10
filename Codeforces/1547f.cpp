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

int stable[500000][30];

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr(2*n);
		for(int i=0; i<n; i++){
			cin >> arr[i];
			arr[i+n] = arr[i];
		}

		for(int i=0; i<2*n; i++){
			for(int j=0; j<30; j++){
				stable[i][j] = -1;
			}
		}

		for(int i=0; i<2*n; i++){
			stable[i][0] = arr[i];
			stable[i][1] = __gcd(arr[i], arr[(i+1)%(2*n)]);
		}

		print(arr);

		for(int i=2*n-2; i>=0; i--){
			for(int j=2; j<30; j++){
				debug(i+(1<<(j-1))-1, i, j);
				if(stable[i][j-1] != -1 && i+(1<<(j-1))-1 < 2*n && stable[i+(1<<(j-1))-1][j-1] != -1){
					stable[i][j] = __gcd(stable[i][j-1], stable[i+(1<<(j-1))-1][j-1]);
				}
			}
		}

		for(int i=0; i<2*n; i++){
			for(int j=0; j<5; j++){
				cout << stable[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";


	}


}

//Read the stuff at the top