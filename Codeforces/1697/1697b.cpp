#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	sort(arr, arr+n);
	int suff[n+1] = {0};
	suff[n-1] = arr[n-1];
	for(int i=n-2; i>=0; i--)
		suff[i] = suff[i+1] + arr[i];

	// print(arr, n);
	// print(suff, n+1);

	while(q--){
		int x, y;
		cin >> x >> y;
		cout << suff[n-x] - suff[n-(x-y)] << "\n";
	}
}

