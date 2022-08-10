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
		int n, k;
		cin >> n >> k;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		if(n == 1){
			cout << arr[0] + (k-1) << "\n";
		}

		else if(n == 2){
			if(k == 1)
				cout << max(arr[0], arr[1]) << "\n";
			else
				cout << arr[0] + k-2 + (arr[1]+k-1) << "\n";
		}

		else{
			if(k <= n){
				int tot = 0;
				for(int i=0; i<k; i++)
					tot += arr[i];

				int maxval = tot;
				for(int j=k; j<n; j++){
					tot -= arr[j-k];
					tot += arr[j];
					maxval = max(maxval, tot);
				}

				cout << maxval + k*(k-1)/2 << "\n";
			}
			else{
				int tot = 0;
				for(int i=0; i<n; i++)
					tot += arr[i];

				cout << (tot + n*k) - n*(n+1)/2 << "\n";
			}
		}
	}
}

