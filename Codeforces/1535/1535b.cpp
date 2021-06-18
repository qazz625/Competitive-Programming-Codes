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
		int n;
		cin >> n;
		vector<int> even, odd;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			if(x%2 == 0)
				even.push_back(x);
			else
				odd.push_back(x);
		}

		vector<int> arr = even;
		for(auto x: odd)
			arr.push_back(x);

		int ans = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(__gcd(arr[i], 2*arr[j]) > 1)
					ans++;
			}
		}
		cout << ans << "\n";
	}


}
