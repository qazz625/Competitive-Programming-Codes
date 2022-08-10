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

	int p10[19];
	p10[0] = 1;
	for(int i=1; i<19; i++){
		p10[i] = p10[i-1]*10;
	}

	while(t--){
		int n, k;
		cin >> n >> k;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		sort(arr, arr+n);
		k++;

		int ans = 0;
		for(int i=0; i<n-1 && k > 0; i++){
			if( k > p10[arr[i+1] - arr[i]] - 1){
				ans += (p10[arr[i+1] - arr[i]] - 1) * p10[arr[i]];
				k -= (p10[arr[i+1] - arr[i]] - 1);
			}
			else{
				ans += k*p10[arr[i]];
				k = 0;
			}
		}

		ans += k * p10[arr[n-1]];

		cout << ans << "\n";
	}
}

