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
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		if(n == 3 && arr[1]%2 == 1){
			cout << "-1\n";
			continue;
		}

		int zero = 0, one = 0;
		int nonzeroeven = 0, odd = 0;
		int tot = 0;
		for(int i=1; i<n-1; i++){
			if(arr[i] == 0)
				zero++;
			else if(arr[i] == 1)
				one++;

			if(arr[i]%2 == 0 && arr[i] != 0){
				nonzeroeven++;
			}
			if(arr[i]%2 == 1){
				odd++;
			}

			tot += (arr[i]+1)/2;
		}

		if(zero+one == n-2){
			cout << "-1\n";
			continue;
		}

		if(nonzeroeven != 0){
			cout << tot << "\n";
		}
		else if(odd != 1){
			cout << tot << "\n";
		}
		else{
			cout << tot+1 << "\n";
		}


	}
}

