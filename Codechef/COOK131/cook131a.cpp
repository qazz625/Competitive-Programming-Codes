#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		map<int, int> mp;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			mp[arr[i]]++;
		}

		int ans = 0;
		for(auto x: mp){
			ans += min(x.first-1, x.second);
		}
		cout << ans << "\n";
	}
}
