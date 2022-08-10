#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int l, r, k;
		cin >> l >> r >> k;
		if(l == r){
			if(r == 1){
				cout << "NO\n";
			}
			else{
				cout << "YES\n";
			}
		}
		else if((r-l+1) - (r/2 - (l-1)/2) <= k){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}

