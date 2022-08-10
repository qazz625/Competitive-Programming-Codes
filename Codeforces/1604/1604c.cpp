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

		int nocount = 0;
		int flag = 0;
		for(int i=0; i<n; i++){
			if(arr[i]%(i+2) != 0){
				nocount++;
				continue;
			}

			int ind = -1;
			for(int j=i-1; j>=max(0ll, i-100); j--){
				if(arr[i]%(j+2) != 0){
					ind = j;
					break;
				}
			}

			if(ind == -1 || nocount < i-ind){
				flag = 1;
				break;
			}
			else{
				nocount++;
			}
		}

		if(flag == 1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
}
