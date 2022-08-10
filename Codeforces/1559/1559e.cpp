#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

#define MAX 100010

int mod = 998244353;

int nearest_lesser(int n, int div){
	return n/div * div;
}

int nearest_greater(int n, int div){
	if(n%div == 0)
		return n;
	else
		return (n/div + 1) * div;
}

int dp[55][100010];
int pref[55][100010];

int ways(int m, int div, vector<pair<int, int>> vp){
	m = nearest_lesser(m, div)/div;
	for(int i=0; i<vp.size(); i++){
		vp[i].first = nearest_greater(vp[i].first, div)/div;
		vp[i].second = nearest_lesser(vp[i].second, div)/div;
		if(vp[i].first > vp[i].second)
			return 0;
	}

	debug(div, m);
	print(vp);

	int n = vp.size();

	for(int i=0; i<55; i++){
		for(int j=0; j<MAX; j++){
			dp[i][j] = 0;
			pref[i][j] = 0;
		}
	}

	for(int i=vp[0].first; i<=vp[0].second; i++){
		dp[0][i] = 1;
	}

	for(int i=1; i<=m; i++){
		pref[0][i] = pref[0][i-1] + dp[0][i];
		pref[0][i] %= mod;
	}

	for(int i=1; i<n; i++){
		for(int j=1; j<=m; j++){
			int lower = max(0ll, j-vp[i].second);
			int upper = max(0ll, j-vp[i].first);

			if(lower == 0){
				dp[i][j] = pref[i-1][upper];
			}
			else{
				dp[i][j] = pref[i-1][upper] - pref[i-1][lower-1];
				dp[i][j] %= mod;
			}
		}

		for(int j=1; j<=m; j++){
			pref[i][j] = pref[i][j-1] + dp[i][j];
			pref[i][j] %= mod;
		}
	}


	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<=m; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";

	debug(pref[n-1][m]);

	return pref[n-1][m];
}

int sieve[MAX];
int primemap[MAX];
set<int> primefactors[MAX];

void solve(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> arr(n);

	vector<int> primes;
	for(int i=2; i<MAX; i++){
		if(sieve[i] == 0){
			primes.push_back(i);
			for(int j=i; j<MAX; j+=i)
				sieve[j] = i;
		}
	}

	for(int i=2; i<MAX; i++){
		int num = i;
		while(num != 1){
			primefactors[i].insert(sieve[num]);
			num /= sieve[num];
		}
	}

	// for(int i=0; i<40; i++){
	// 	print(primefactors[i]);
	// }

	// print(primes);

	// print(sieve, 40);

	for(int i=0; i<n; i++){
		cin >> arr[i].first >> arr[i].second;
	}

	// print(arr);

	int tot = ways(m, 1, arr);

	for(int i=2; i<=m; i++){
		int cur = ways(m, i, arr);
		// debug(p, cur);
		primemap[i] = cur;
	}

	// print(primemap, m+1);


	int included[m+1] = {0};
	int ans = 0;
	for(int i=m; i>=2; i--){
		included[i] += 1;
		ans += primemap[i];
		ans %= mod;
		for(int j=i; j<=m; j+=i){
			if(included[j] > 1){
				for(int k=j; k<=m; k+=j){
					int diff = included[j]-1;
					included[k] -= diff*1;
					ans -= primemap[k]*diff;
					ans %= mod;
				}
			}
			else if(included[j] == 0){
				for(int k=j; k<=m; k+=j){
					included[k] += 1;
					ans += primemap[k];
					ans %= mod;
				}
			}
		}
	}

	debug(tot, ans);

	tot -= ans;
	tot += mod;
	tot %= mod;

	print(included, m+1);

	cout << tot << "\n";


}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
