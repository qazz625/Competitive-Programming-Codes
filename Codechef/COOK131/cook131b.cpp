#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<int, int> mp;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			mp[x]++;
		}

		int minnum = mp.begin()->first;
		int flag = 0;
		for(auto x: mp){
			if(minnum >= (x.first + x.first%2)/2 && x.first != minnum){
				flag = 1;
			}
		}

		if(flag == 1){
			cout << n << "\n";
		}
		else{
			cout << n - mp.begin()->second << "\n";
		}
	}


}
