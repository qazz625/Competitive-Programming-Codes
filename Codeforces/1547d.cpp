#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../debug.cpp"
#endif

/*
0011
0101
0111
1111

0000
0010
0000
0000


0001
0010
0100
1000
*/

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0; i<n; i++)
			cin >> arr[i];

		vector<int> ans(n);
		ans[0] = 0;
		int cur = arr[0];
		for(int i=1; i<n; i++){
			int num = 0;
			for(int j=0; j<=30; j++){
				// debug(arr[i], cur);
				if((cur&(1<<j)) != 0 && (arr[i]&(1<<j)) == 0){
					num += 1<<j;
				}
			}
			ans[i] = num;

			cur |= arr[i];
		}

		for(auto x: ans)
			cout << x << " ";
		cout << "\n";
	}


}
