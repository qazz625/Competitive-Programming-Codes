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
		string s;
		cin >> s;

		vector<pair<int, char>> arr;
		int count = 1;
		for(int i=0; i<n-1; i++){
			if(s[i] == s[i+1])
				count += 1;
			else{
				arr.push_back({count, s[i]});
				count = 1;
			}
		}
		arr.push_back({count, s[n-1]});

		if(arr.size() <= 2){
			cout << "NO\n";
			continue;
		}

		print(arr);

		int ptr1 = 0, ptr2 = arr.size()-1;

		int flag = 0;
		while(ptr1 < ptr2){
			if(arr[ptr1].second == 'M' || arr[ptr2].second == 'M'){
				flag = 1;
				break;
			}
			int mcount = 0;
			if(ptr2-ptr1 > 2){
				mcount += arr[ptr1+1].first;
				mcount += arr[ptr2-1].first;
			}
			else{
				mcount += arr[ptr1+1].first;
			}

			int tcount = arr[ptr1].first+arr[ptr2].first;

			if(tcount < mcount*2){
				flag = 1;
				break;
			}

			debug(mcount, tcount);

			tcount -= mcount*2;
			ptr1 += 2;
			ptr2 -= 2;
			arr[ptr1].first += tcount;
		}

		debug(flag);
		if(flag == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}



	}


}

//Read the stuff at the top