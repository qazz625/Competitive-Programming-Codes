#include <bits/stdc++.h>
using namespace std;

#define int long long

// #ifndef ONLINE_JUDGE
// 	#define _GLIBCXX_DEBUG
// 	#include "../../../debug.cpp"
// #endif

int32_t main(){

	int t;
	cin >> t;
	for(int tt=1; tt<=t; tt++){
		int g;
		cin >> g;
		int ans = 0;
		for(int i=1; 2*g-i*i+i > 0; i++){
			if( (2*g-i*i+i)%(2*i) == 0){
				ans++;
			}
		}

		cout << "Case #" << tt << ": ";
		cout << ans << "\n";
	}

}

