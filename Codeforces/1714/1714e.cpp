#include <bits/stdc++.h>
using namespace std;

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
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		int same = 0;
		for(int i=0; i<n; i++){
			if(arr[i] == arr[0])
				same++;
		}

		if(same == n){
			cout << "Yes\n";
			continue;
		}

		int zero = 0;
		for(int i=0; i<n; i++){
			if(arr[i]%2){
				arr[i] += arr[i]%10;
			}
			if(arr[i]%10 == 0)
				zero++;
		}

		if(zero){
			int same = 0;
			for(int i=0; i<n; i++){
				if(arr[i] == arr[0])
					same++;
			}

			if(same != n){
				cout << "No\n";
			}
			else{
				cout << "Yes\n";
			}
			continue;
		}

		for(int i=0; i<n; i++){
			while(arr[i]%10 != 2){
				arr[i] += arr[i]%10;
				// debug("AA");
			}
		}

		string ans = "Yes";
		for(int i=1; i<n; i++){
			if((arr[i] - arr[i-1])%20 != 0){
				ans = "No";
			}
		}
		cout << ans << "\n";
	}
}
