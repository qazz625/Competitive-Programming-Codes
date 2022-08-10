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
		int n, k;
		cin >> n >> k;

		int cur = 1, time = 0;
		n--;
		while(cur < k){
			n = max(n-cur, 0ll);
			cur  = min(2*cur, k);
			time++;
		}

		time += n/k;
		if(n%k != 0)
			time++;

		cout << time << "\n";
	}


}

//Read the stuff at the top