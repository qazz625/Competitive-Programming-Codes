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
		int n;
		cin >> n;
		map<int, int> mp;
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
			mp[arr[i]]++;
		}


		int doubles = 0;
		int singles = 0;
		for(auto x: mp){
			if(x.second >= 2){
				doubles++;
			}
			else{
				singles++;
			}
		}

		int ans = doubles + (singles+1)/2;
		cout << ans << "\n";
	}
}
