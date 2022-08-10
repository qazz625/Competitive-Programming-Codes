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
		int mincur = 0, maxcur = 0;
		string s;
		cin >> s;
		vector<pair<int, int>> pref(10);
		for(int i=0; i<10; i++){
			if(s[i] == '1' && i%2 == 0){
				maxcur++;
				mincur++;
			}
			else if(s[i] == '?' && i%2 == 0){
				maxcur++;
			}
			else if(s[i] == '1' && i%2 == 1){
				mincur--;
				maxcur--;
			}
			else if(s[i] == '?' && i%2 == 1){
				mincur--;
			}
			pref[i] = {mincur, maxcur};
		}

		mincur = 0, maxcur = 0;
		vector<pair<int, int>> suff(10);
		for(int i=9; i>=0; i--){
			if(i%2 == 0){
				maxcur++;
				// mincur++;
			}
			// else if(s[i] == '?' && i%2 == 0){
			// 	maxcur++;
			// }
			else if(i%2 == 1){
				mincur--;
			}
			// else if(s[i] == '?' && i%2 == 1){
			// 	mincur--;
			// }
			suff[i] = {mincur, maxcur};
		}

		// print(pref);
		// print(suff);


		int ans = -1;
		for(int i=0; i<9; i++){
			bool cond1 = pref[i].first+suff[i+1].first < 0 && pref[i].first+suff[i+1].second < 0;
			bool cond2 = pref[i].first+suff[i+1].first > 0 && pref[i].first+suff[i+1].second > 0;
			bool cond3 = pref[i].second+suff[i+1].first < 0 && pref[i].second+suff[i+1].second < 0;
			bool cond4 = pref[i].second+suff[i+1].first > 0 && pref[i].second+suff[i+1].second > 0;
			// debug(i, cond1, cond2, cond3, cond4);
			if((cond1 || cond2) || (cond3 || cond4)){
				ans = i;
				break;
			}
		}

		if(ans == -1)
			ans = 9;
		cout << ans+1 << "\n";
	}


}

//Read the stuff at the top