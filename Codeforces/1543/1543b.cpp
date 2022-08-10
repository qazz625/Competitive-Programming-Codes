#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;

#define int long long

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
		int arr[n];
		int tot = 0;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			tot += arr[i];
		}

		int greaternum = tot%n;
		int lowernum = n - greaternum;

		cout << greaternum*lowernum << "\n";

	}
}
