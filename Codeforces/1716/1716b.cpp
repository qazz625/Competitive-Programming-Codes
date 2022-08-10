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
		for(int i=0; i<n; i++){
			arr[i] = i+1;
		}

		cout << n << "\n";
		for(int i=0; i<n; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";


		for(int i=n-2; i>=0; i--){
			swap(arr[i], arr[n-1]);
			for(int i=0; i<n; i++)
				cout << arr[i] << " ";
			cout << "\n";
		}

	}


}
