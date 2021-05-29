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
		int n, k;
		cin >> n >> k;
		int flag = 0;
		while(!(k&1))
			k >>= 1;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			x %= k;
			if(x != 0)
				flag = 1;
		}
		if(flag == 1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
}