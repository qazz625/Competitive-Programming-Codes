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
		for(int i=0; i<n; i++)
			cin >> arr[i];

		int pref[n], suff[n];
		pref[0] = arr[0];
		for(int i=1; i<n; i++)
			pref[i] = pref[i-1]^arr[i];

		suff[n-1] = arr[n-1];
		for(int i=n-2; i>=0; i--){
			suff[i] = suff[i+1]^arr[i];
		}


		int flag = 0;
		for(int i=0; i<n-1; i++){
			if(pref[i] == suff[i+1]){
				flag = 1;
				break;
			}
		}

		if(flag == 1){
			cout << "YES\n";
			continue;
		}

		if(n == 2){
			cout << "NO\n";
			continue;
		}

		for(int i=0; i<n-2; i++){
			int p = pref[i];
			int curxor = 0;
			for(int j=i+1; j<n-1; j++){
				curxor ^= arr[j];
				if(pref[i] == curxor && curxor == suff[j+1]){
					flag = 1;
					break;
				}
			}
		}

		if(flag == 1){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}
