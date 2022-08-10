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
		vector<int> arr(n);
		int maxval = -1;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			maxval = max(maxval, arr[i]);
		}

		if(n == 1){
			cout << "0\n";
			continue;
		}

		sort(arr.begin(), arr.end());

		for(int i=0; i<n-1; i++)
			arr[i] = arr[i+1]-arr[i];

		arr.pop_back();
		// print(arr);


		int pref[n] = {0};
		pref[0] = arr[0];
		for(int i=1; i<n-1; i++)
			pref[i] = pref[i-1] + arr[i];

		int pref2[n] = {0};
		pref2[0] = pref[0];
		for(int i=1; i<n-1; i++)
			pref2[i] = pref2[i-1] + pref[i];

		// print(pref, n-1);
		// print(pref2, n-1);
		int ans = pref2[n-2];
		// debug(ans);
		for(int i=0; i<n-1; i++){
			// debug(i, n-(i+1), pref2[n-2], pref2[i], pref[i]);
			ans += pref2[n-2] - pref2[i] - (n-1-(i+1))*pref[i];
		}
		cout << maxval - ans << "\n";
	}


}

