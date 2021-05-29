#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> factors[200010];
	for(int i=1; i<200010; i++){
		for(int j=1; j*j<=i; j++){
			if(i%j == 0){
				factors[i].push_back(j);
				factors[i].push_back(i/j);
			}
		}
	}

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		sort(arr, arr+n);

		map<int, int> dp;
		dp[arr[0]] = 1;

		for(int i=1; i<n; i++){
			int cur = 1;
			for(auto x: factors[arr[i]])
				if(dp.find(x) != dp.end())
					cur = max(cur, dp[x]+1);
			dp[arr[i]] = cur;
		}

		int ans = 0;
		for(auto x: dp)
			ans = max(ans, x.second);

		cout << n-ans << "\n";
	}
}
