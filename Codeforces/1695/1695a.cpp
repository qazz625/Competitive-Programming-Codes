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
		int maxval = 0;
		int ival, jval;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> arr[i][j];
				if(arr[i][j] > maxval){
					maxval = arr[i][j];
					ival = i;
					jval = j;
				}
			}
		}
		int one = (ival+1)*(jval+1);
		int two = (n-ival)*(jval+1);
		int three = (ival+1)*(m-jval);
		int four = (n-ival)*(m-jval);

		cout << max({one, two, three, four}) << "\n";


	}


}
