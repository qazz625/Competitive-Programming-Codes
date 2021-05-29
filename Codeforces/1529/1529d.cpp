#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod = 998244353;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int dp[3000010];
int pref[3000010];

int sieve[3000010];

int countfactors(int n){
	int count = 0;
	int factors = 1, prev = -1;
	int twocount = 0;
	// debug(n);
	while(n != 1){
		if(sieve[n] == prev){
			count += 1;
		}
		else{
			factors *= (count+1);
			count = 1;
		}
		if(sieve[n] == 2)
			twocount++;
		prev = sieve[n];
		n /= sieve[n];
	}
	factors *= (count+1);
	return factors - factors/(twocount+1);
}

int32_t main(){
	int n;
	cin >> n;

	for(int i=2; i<2000010; i++){
		if(sieve[i] == 0){
			for(int j=i; j<2000010; j+=i){
				sieve[j] = i;
			}
		}
	}

	// cout << countfactors(4) << "\n";

	// for(int i=1; i<20; i++){
	// 	cout << countfactors(i) << " ";
	// }
	// cout << "\n";

	// print(sieve, 20);

	dp[0] = 1;
	pref[0] = 1;
	dp[2] = 1;
	pref[2] = 2;
	n *= 2;
	// debug(n);
	// debug("AA");
	for(int i=4; i<=n; i+=2){
		dp[i] = pref[i-2] + countfactors(i)-1;
		pref[i] = pref[i-2] + dp[i];
		pref[i] %= mod;
		dp[i] %= mod;
	}

	// print(dp, 16);
	// print(pref, 16);

	// cout << dp[n] << "\n";
	for(int i=2; i<=200000; i+=2){
		cout << dp[i] << "\n";
	}
}

