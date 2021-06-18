#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int mod = 1000000007;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr1(n), arr2(n);

		int arr1ind[n] = {0};
		for(int i=0; i<n; i++){
			cin >> arr1[i];
			arr1[i]--;
			arr1ind[arr1[i]] = i;
		}
		for(int j=0; j<n; j++){
			cin >> arr2[j];
			arr2[j]--;
		}

		// print(arr1ind, n);

		int done[n] = {0};
		int ans = 1;
		for(int i=0; i<n; i++){
			if(done[i] == 0){
				int cur = i;
				while(done[cur] == 0){
					// debug(cur);
					done[cur] = 1;
					cur = arr1ind[arr2[cur]];
				}
				ans *= 2;
				ans %= mod;
			}
		}
		cout << ans << "\n";
	}


}

