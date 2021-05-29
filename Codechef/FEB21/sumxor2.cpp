#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int prefsum[30][200010];
int factorial[200010];
int modinv[200010];
int mod = 998244353;

int binpow(int a, int b){
	if(b == 0)
		return 1;
	int x = binpow(a, b/2);
	x = x*x % mod;
	if(b%2 == 0)
		return x;
	else
		return x*a % mod;
}

int nCr(int n, int r){
	if(r > n)
		return 0;
	return (factorial[n]*modinv[r] % mod)*modinv[n-r] % mod;
}

void solve(){
	int n;
	cin >> n;
	int arr[n];
	vector<pair<int, int>> bits(30);
	for(int i=0; i<n; i++){
		cin >> arr[i];
		for(int j=0; j<30; j++)
			if(arr[i]&(1<<j))
				bits[j].second++;
	}

	for(int i=0; i<30; i++)
		bits[i].first = n-bits[i].second;

	print(bits);

	for(int i=0; i<30; i++){
		// calc(bits[i].second, bits[i].first);
	}


}


int32_t main(){
	int t;
	t = 1;

	factorial[0] = 1;
	for(int i=1; i<200010; i++)
		factorial[i] = i*factorial[i-1] % mod;
	for(int i=0; i<200010; i++)
		modinv[i] = binpow(factorial[i], mod-2);

	print(factorial, 10);
	print(modinv, 10);

	while(t--){
		solve();
	}
}