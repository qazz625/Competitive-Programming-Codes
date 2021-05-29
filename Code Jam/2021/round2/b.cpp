#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../../debug.cpp"
#endif

#define MAX 100

int dp[MAX][2];

int sieve[MAX];
vector<int> primes;

vector<int> factors[MAX];

void generate_factors(int ind, vector<pair<int, int>> &v, int num, int prod){
	if(ind == v.size()){
		factors[num].push_back(prod);
		return;
	}

	for(int i=0; i<=v[ind].second; i++){
		generate_factors(ind+1, v, num, prod);
		prod *= v[ind].first;
	}
}

void solve(int n, int flag){
	// debug(n);

	int ans = 0, ans2 = 0;
	for(auto x: factors[n]){
		if(x != 1){
			if(dp[n/x-1][0] == 0)
				solve(n/x-1, 0);
			if(dp[n/x-1][1] == 0)
				solve(n/x-1, 1);
			ans = max(ans, dp[n/x-1][0]+1);
			ans = max(ans, dp[n/x-1][1]+1);
			ans2 = max(ans2, dp[n/x-1][1]+1);
		}
	}
	dp[n][0] = ans;
	dp[n][1] = ans2;

	// debug(n, dp[n]);
}

int32_t main(){

	for(int i=2; i<MAX; i++){
		if(sieve[i] == 0){
			primes.push_back(i);
			for(int j=i; j<MAX; j+=i){
				sieve[j] = i;
			}
		}
	}

	for(int i=2; i<MAX; i++){
		vector<pair<int, int>> v;
		int num = i;
		int prev = -1;
		while(num != 1){
			if(sieve[num] != prev){
				v.push_back({sieve[num], 1});
				prev = sieve[num];
			}
			else{
				v.back().second++;
			}
			num /= sieve[num];
		}
		generate_factors(0, v, i, 1);
	}

	dp[2][0] = 0;
	dp[2][2] = 1;

	// solve(9, 0);
	// solve(9, 0);

	for(int i=3; i<MAX; i++){
		solve(i, 1);
		// cout << i << " " << dp[2] << "\n";
	}

	// cout << dp[33];
	// solve(6, 0);
	// solve(14, 0);
	// solve(15, 0);
	solve(10, 1);
	solve(33, 1);
	// cout << dp[10] << "\n";
	int t;
	cin >> t;
	for(int tt=1; tt<=t; tt++){
		int n;
		cin >> n;
		cout << "Case #" << tt << ": ";
		cout << dp[n][0] << "\n";
	}
}
