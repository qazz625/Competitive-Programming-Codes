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
		int n, m;
		cin >> n >> m;

		int arr[n][m];
		for(int i=0; i<n; i+=2){
			int cur = (i/2)%2;
			for(int j=0; j<m; j+=2){
				arr[i][j] = cur;
				arr[i+1][j] = cur^1;
				arr[i][j+1] = cur^1;
				arr[i+1][j+1] = cur;
				cur ^= 1;
			}
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}


}

