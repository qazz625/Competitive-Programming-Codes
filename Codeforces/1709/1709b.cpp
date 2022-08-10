#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int n, m;
	cin >> n >> m;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	int pref[n] = {0};
	int suff[n] = {0};

	for(int i=1; i<n; i++){
		pref[i] = pref[i-1] + max(0ll, arr[i-1]-arr[i]);
	}
	// print(pref, n);

	for(int i=n-2; i>=0; i--){
		suff[i] = suff[i+1] + max(0ll, arr[i+1]-arr[i]);
	}
	// print(suff, n);

	while(m--){
		int s, t;
		cin >> s >> t;
		s--; t--;
		if(t >= s)
			cout << pref[t]-pref[s] << "\n";
		else
			cout << suff[t]-suff[s] << "\n";
	}
}

