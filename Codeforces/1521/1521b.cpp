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
		int arr[n], mi = 1<<30, ind = -1;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			if(arr[i] < mi){
				mi = arr[i];
				ind = i;
			}
		}

		cout << n-1 << "\n";
		for(int i=0; i<n; i++){
			if(i != ind){
				if(abs(ind-i)%2 == 0)
					cout << i+1 << " " << ind+1 << " " << mi << " " << mi;
				else
					cout << i+1 << " " << ind+1 << " " << mi+1 << " " << mi;
				cout << "\n";
			}
		}
	}
}
