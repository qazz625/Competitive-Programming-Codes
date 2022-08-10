#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int n, q;
	cin >> n >> q;
	int a[n], b[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<n; i++)
		cin >> b[i];

	int arr[n];
	for(int i=0; i<n; i++){
		arr[i] = a[i]-b[i];
	}

	print(arr, n);

	int pref[n+1] = {0};
	pref[0] = 0;
	for(int i=1; i<=n; i++){
		pref[i] = arr[i-1] + pref[i-1];
	}

	print(pref, n+1);

	while(q--){
		int l, r;
		cin >> l >> r;
		int netdiff = pref[r] - pref[l-1];

		if(netdiff != 0){
			cout << "-1\n";
			continue;
		}
		debug("AA");
	}


}

