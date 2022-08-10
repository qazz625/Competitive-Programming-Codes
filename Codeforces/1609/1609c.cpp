#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n, e;
int sieve[1000010];


int solve(vector<int> &temp){
	int ans = 0;
	// print(temp);
	for(int i=0; i<temp.size(); i++){
		if(sieve[temp[i]] == 1){
			int prev = 0;
			for(int j=i-1; j>=0 && temp[j] == 1; j--){
				prev++;
			}

			int after = 0;
			for(int j=i+1; j<temp.size() && temp[j] == 1; j++){
				after++;
			}

			int cur = (prev+1)*(after+1)-1;
			// debug(prev, after, cur);
			ans += cur;
		}
	}
	return ans;
}

int32_t main(){
	int t;
	cin >> t;

	for(int i=0; i<1000010; i++)
		sieve[i] = 1;

	sieve[1] = 0;
	sieve[0] = 0;
	for(int i=2; i<1000010; i++){
		if(sieve[i] == 1){
			for(int j=2*i; j<1000010; j+=i){
				sieve[j] = 0;
			}
		}
	}

	// print(sieve, 20);
	while(t--){
		cin >> n>> e;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		int ans = 0;
		for(int i=0; i<e; i++){
			vector<int> temp;
			for(int j=i; j<n; j+=e){
				temp.push_back(arr[j]);
			}
			ans += solve(temp);
		}

		cout << ans << "\n";

	}
}