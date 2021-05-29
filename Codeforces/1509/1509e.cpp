#include <bits/stdc++.h>
using namespace std;

#define int long long

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
		int n, k;
		cin >> n >> k;
		
		if(n <= 62 && (1ll<<(n-1)) < k){
			cout << "-1\n";
			continue;
		}


		int ind = 1;
		for(; n-ind+1 > 62; ind++){
			cout << ind << " ";
		}
		int rem = n-ind+1;

		while(ind <= n){
			int tot = 0;
			int ans;
			if(rem <= 62 && (1ll<<(rem-1)) == k){
				for(int i=n; i>=ind; i--){
					cout << i << " ";
				}
				break;
			}


			for(int i=ind; i<=n; i++){
				if(tot + (1ll<<(rem-(i-ind)-2)) >= k){
					ans = i;
					break;
				}
				tot += 1ll<<(rem-(i-ind)-2);
			}
			// debug(k, ind, ans);

			for(int i=ans; i>=ind; i--){
				cout << i << " ";
				rem--;
			}
			// print(res);
			k -= tot;
			ind = ans+1;
			// debug(k, ind, ans);
		}
		cout << "\n";

	}
}
