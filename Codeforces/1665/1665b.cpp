#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
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
		int n;
		cin >> n;
		int arr[n];
		map<int, int> mp;
		int maxfreq = 0;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			mp[arr[i]]++;
			maxfreq = max(maxfreq, mp[arr[i]]);
		}

		// debug(maxfreq);

		int rem = n-maxfreq;

		int ans = 0;
		while(rem > 0){
			// debug(ans, rem, maxfreq);
			ans++; //copy
			if(maxfreq <= rem){
				rem -= maxfreq;
				ans += maxfreq;
				maxfreq *= 2;
			}
			else{
				ans += rem;
				maxfreq += rem;
				rem = 0;
			}
		}

		// int ans = rem + rem/maxfreq;
		// if(rem%maxfreq != 0)
		// 	ans++;

		cout << ans << "\n";
	}
}
