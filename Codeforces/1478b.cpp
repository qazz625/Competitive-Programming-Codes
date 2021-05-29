#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../debug.cpp"
#endif


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int arr[n];
		string ans = "NO\n";
		// debug(k);

		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		sort(arr, arr+n);

		int g = 0;
		for(int i=1; i<n; i++)
			g = __gcd(g, arr[i]-arr[i-1]);

		for(int i=0; i<n; i++){
			if(abs(k-arr[i])%g == 0)
				ans = "YES\n";
		}
		cout << ans;
	}
}
