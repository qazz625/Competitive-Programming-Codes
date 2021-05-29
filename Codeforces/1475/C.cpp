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


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int a, b, k;
		cin >> a >> b >> k;
		int boys[a+1] = {0};
		int girls[b+1] = {0};

		vector<pair<int, int>> arr(k);
		for(int i=0; i<k; i++){
			cin >> arr[i].first;
			boys[arr[i].first]++;
		}
		for(int i=0; i<k; i++){
			cin >> arr[i].second;
			girls[arr[i].second]++;
		}

		int ans = 0;
		for(int i=0; i<k; i++){
			int num = k-(boys[arr[i].first] + girls[arr[i].second]) + 1;
			ans += num;
		}
		cout << ans/2 << "\n";
	}
}
