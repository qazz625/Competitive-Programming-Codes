#include <bits/stdc++.h>
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
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		if(n%2 == 1){
			int tot = 0;
			for(int i=1; i<n-1; i+=2){
				tot += max(0ll, max(arr[i-1], arr[i+1])+1 - arr[i]);
			}
			cout << tot << "\n";
			continue;
		}

		if(n == 2){
			cout << 0 << "\n";
			continue;
		}

		int pref[n] = {0}, suff[n] = {0};

		pref[1] = max(0ll, max(arr[0], arr[2])+1 - arr[1]);
		suff[n-2] = max(0ll, max(arr[n-3], arr[n-1])+1 - arr[n-2]);

		for(int i=3; i<n-1; i+=2){
			int cur = max(0ll, max(arr[i-1], arr[i+1])+1 - arr[i]);
			pref[i] = pref[i-2] + cur;
		}

		for(int i=n-4; i>0; i-=2){
			int cur = max(0ll, max(arr[i-1], arr[i+1])+1 - arr[i]);
			suff[i] = suff[i+2] + cur;
		}

		int ans = min(pref[n-3], suff[2]);
		for(int i=1; i<n-3; i+=2){
			ans = min(ans, pref[i]+suff[i+3]);
		}

		// print(pref, n);
		// print(suff, n);

		// debug("AA");

		cout << ans << "\n";
	}
}

