#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	int ans = 0;
	for(int i=0; i<n; i+=2){
		int tot = 0;
		int minlstart = 1, minrstart = 1;
		for(int j=i+1; j<n; j+=2){
			pair<int, int> l = {1, arr[i]};
			pair<int, int> r = {1, arr[j]};
			int temp;

			//how many pairs sum up to (-tot)
			if(tot >= 0){
				//more in r
				int lstart = max(1ll, minlstart);
				int rstart = tot+lstart;
				int rrange = arr[j]-rstart+1;
				int lrange = arr[i]-lstart+1;
				// debug(lstart, rstart, lrange, rrange);
				temp = max(min(rrange, lrange), 0ll);
			}
			else{
				//more in l
				int rstart;
				int aa = tot+minlstart;
				if(aa > 0)
					rstart = aa;
				else
					rstart = 1;
				int lstart = max(abs(tot)+1, minlstart);
				int rrange = arr[j]-rstart+1;
				int lrange = arr[i]-lstart+1;
				// debug(lstart, rstart, lrange, rrange, minrstart);
				temp = max(min(rrange, lrange), 0ll);
			}
			// debug(i, j, temp, tot, minlstart);

			ans += temp;

			tot -= arr[j];
			if(tot+arr[i] < 0)
				break;
			else if(tot < 0){
				minlstart = max(minlstart, abs(tot));
			}

			if(j+1 < n)
				tot += arr[j+1];

			// if(tot > 0){
			// 	minrstart = max(minrstart, tot);
			// }
		}
	}
	cout << ans << "\n";
}


int32_t main(){
	int t;
	// cin >> t;
	t = 1;
	while(t--){
		solve();
	}
}

