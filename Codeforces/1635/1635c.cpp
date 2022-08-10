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
		multiset<int> ms, diff;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			ms.insert(arr[i]);
		}

		if(arr[n-2] > arr[n-1]){
			cout << "-1\n";
			continue;
		}

		if(arr[n-1] >= 0){
			cout << n-2 << "\n";
			for(int i=n-3; i>=0; i--){
				arr[i] = arr[n-2] - arr[n-1];
				cout << i+1 << " " << n-1 << " " << n << "\n";
			}
		}
		else{
			int flag = 0;
			for(int i=1; i<n; i++){
				if(arr[i] < arr[i-1])
					flag = -1;
			}
			cout << flag << "\n";
		}
	}
}

