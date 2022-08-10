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
		for(int i=0; i<n; i++)
			cin >> arr[i];
		sort(arr, arr+n);

		if(n == 2){
			cout << arr[0] << " " << arr[1] << "\n";
			continue;
		}

		int mi = 1<<30;
		int ind1 = -1, ind2 = -1;
		for(int i=1; i<n; i++){
			if(arr[i]-arr[i-1] < mi){
				ind1 = i;
				ind2 = i-1;
				mi = arr[i]-arr[i-1];
			}
		}

		for(int i=ind1; i<ind1+n; i++){
			cout << arr[i%n] << " ";
		}
		cout << "\n";

	}
}

