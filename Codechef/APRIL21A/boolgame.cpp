#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		int marr[n][n], subarrval[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				marr[i][j] = 0;
				subarrval[i][j] = 0;
			}
		}

		for(int i=0; i<m; i++){
			int u, v, val;
			cin >> u >> v >> val;
			marr[u-1][v-1] = val;
		}

		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				for(int x=i; x<=j; x++)
					for(int y=x; y<=j; y++)
						subarrval[i][j] += marr[x][y];

				for(int x=i; x<=j; x++)
					subarrval[i][j] += arr[x];
			}
		}

		multiset<int> dp[n][2];
		dp[0][0].insert(0);
		dp[0][1].insert(arr[0]);

		for(int i=1; i<n; i++){
			multiset<int> cur0;
			for(int pos = 0; pos<2; pos++){
				for(auto x: dp[i-1][pos]){
					if(cur0.size() < k)
						cur0.insert(x);
					else if(*cur0.begin() < x){
						cur0.erase(cur0.begin());
						cur0.insert(x);
					}
				}
			}	

			dp[i][0] = cur0;

			multiset<int> cur1;
			for(int j=i; j>0; j--){
				int val = subarrval[j][i];
				for(auto x: dp[j-1][0]){
					if(cur1.size() < k)
						cur1.insert(x+val);
					else if(*cur1.begin() < x+val){
						cur1.erase(cur1.begin());
						cur1.insert(x+val);
					}
				}
			}
			int val = subarrval[0][i];
			if(cur1.size() < k)
				cur1.insert(val);
			else if(*cur1.begin() < val){
				cur1.erase(cur1.begin());
				cur1.insert(val);
			}
			dp[i][1] = cur1;
		}

		vector<int> res;
		for(auto x: dp[n-1][0])
			res.push_back(x);
		for(auto x: dp[n-1][1])
			res.push_back(x);

		sort(res.begin(), res.end(), greater<int>());

		for(int i=0; i<k; i++)
			cout << res[i] << " ";
		cout << "\n";
		
	}
}
