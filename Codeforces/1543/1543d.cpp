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
		int n, base;
		cin >> n >> base;
		int done = 0;
		cout << 0 << endl;
		cin >> done;
		if(done == 1)
			continue;

		for(int i=1; i<n; i++){
			int k = 0;
			int num = i;
			while((num&1) == 0){
				k++;
				num >>= 1;
			}
			int val = (1<<(k+1)) - 1;
			cout << val << endl;
			cin >> done;
			if(done == 1)
				break;
		}


	}
}
