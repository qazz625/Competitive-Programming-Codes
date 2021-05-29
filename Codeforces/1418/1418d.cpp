/*
THINGS TO DO
1) Check integer overflows
2) Check corner cases
3) Compile and run once on terminal
4) Code smart, not quick
*/

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds_set;

int answer(pbds_set &s, int n){
	if(n%2 == 0){
		int mid = n/2;
		return *(s.find_by_order(n-1)) - *(s.find_by_order(mid)) + *(s.find_by_order(mid-1)) - *(s.find_by_order(0));
	}

	else{
		int mid = n/2;
		// cout << *(s.find_by_order(0));
		int a = *(s.find_by_order(n-1)) - *(s.find_by_order(mid)) + *(s.find_by_order(mid-1)) - *(s.find_by_order(0));
		int b = *(s.find_by_order(n-1)) - *(s.find_by_order(mid+1)) + *(s.find_by_order(mid)) - *(s.find_by_order(0));
		return min(a, b);
	}
}


int32_t main(){
	int n, q, i, j;
	cin >> n >> q;

	pbds_set s;
	for(i=0; i<n; i++){
		cin >> j;
		s.insert(j);
	}

	cout << answer(s, n) << "\n";

	for(auto x: s)
			cout << x << " ";
		cout << "\n";

	while(q--){
		int type, x;
		cin >> type >> x;
		if(type == 1){
			s.insert(x);
			n++;
			cout << answer(s, n) << "\n";
		}
		else{
			s.erase(s.find(x));
			n--;
			cout << answer(s, n) << "\n";
		}
		for(auto x: s)
			cout << x << " ";
		cout << "\n";
	}
}

//Read the stuff at the top