#include <bits/stdc++.h>
using namespace std;

#define int long long

int inf = 1ll<<40;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../debug.cpp"
#endif

/*
suffix
tj + aj - i = temp(i)
min(tj + aj) - i


prefix
tj + i - aj
min(tj - aj) + i

*/
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> location(n);
		vector<int> arr(n);
		for(int i=0; i<k; i++){
			cin >> location[i];
			location[i]--;
		}
		for(int i=0; i<k; i++){
			cin >> arr[location[i]];
		}

		// print(arr);


		vector<int> ans(n);
		vector<int> pref(n), suff(n);

		if(arr[0] == 0)
			pref[0] = inf;
		else
			pref[0] = arr[0]-0 - 1;
		for(int i=1; i<n; i++){
			if(arr[i] == 0)
				pref[i] = pref[i-1];
			else
				pref[i] = min(pref[i-1], arr[i]-i - 1);
		}

		if(arr[n-1] == 0)
			suff[n-1] = inf;
		else
			suff[n-1] = n-1 + arr[n-1] + 1;
		for(int i=n-2; i>=0; i--){
			if(arr[i] == 0)
				suff[i] = suff[i+1];
			else
				suff[i] = min(suff[i+1], arr[i]+i + 1);
		}

		// print(pref);
		// print(suff);

		for(int i=0; i<n; i++){
			ans[i] = min(pref[i]+i+1, suff[i]-i-1);
		}
		

		for(auto x: ans){
			cout << x << " ";
		}
		cout << "\n";

		
	}
}
