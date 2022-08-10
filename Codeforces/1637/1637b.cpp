#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int findmex(set<int> &s){
	int curmax = -1;
	for(auto x: s){
		if(x == curmax+1)
			curmax = x;
	}
	return curmax+1;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}


		int ans = 0;
		for(int i=0; i<n; i++){
			int dp[n] = {0};
			for(int j=i; j<n; j++){
				set<int> s;
				for(int k=j; k>=i; k--){
					s.insert(arr[k]);
					int mex = findmex(s);
					// debug(mex, i, j, k);
					if(k == i){
						dp[j] = max(dp[j], 1+mex);
					}
					else{
						dp[j] = max(dp[j], dp[k-1] + 1+mex);
					}
				}
				ans += dp[j];
			}

		}

		cout << ans << "\n";
	}
}
