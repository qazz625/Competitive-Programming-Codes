#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int n, q;
	cin >> n >> q;
	int one = 0, zero = 0;
	int arr[n];
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		if(x == 1)
			one++;
		else
			zero++;
		arr[i] = x;
	}

	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int x;
			cin >> x;
			x--;
			if(arr[x] == 0){
				zero--;
				one++;
			}
			else{
				one--;
				zero++;
			}
			arr[x] ^= 1;
		}
		else{
			int k;
			cin >> k;
			if(one >= k){
				cout << "1\n";
			}
			else{
				cout << "0\n";
			}
		}
	}
}
