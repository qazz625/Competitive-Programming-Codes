

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
		int even = 0;
		int minval = 1<<30;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			if(arr[i]%2 == 0){
				even++;
				int num = arr[i];
				int temp = 0;
				while(num%2 == 0){
					temp++;
					num /= 2;
				}
				minval = min(minval, temp);
			}
		}

		if(even == n){
			cout << minval + n-1 << "\n";
		}
		else{
			cout << even << "\n";
		}
	}


}

