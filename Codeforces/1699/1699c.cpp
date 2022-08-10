#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

#define MAX 200000

int mod = 1000000007;

int fact[MAX], modinv[MAX];

int binpow(int a, int b, int m){
	if(b == 0)
		return 1;
	int x = binpow(a, b/2, m);
	x = x*x % m;
	if(b%2 == 0)
		return x;
	else
		return x*a%m;
}

int C(int n, int r){
	if(r > n)
		return 0;

	int num = fact[n];
	int denom = modinv[r]*modinv[n-r] % mod;
	return num*denom % mod;
}

int32_t main(){
	int t;
	cin >> t;
	fact[0] = 1;
	for(int i=1; i<MAX; i++){
		fact[i] = fact[i-1]*i % mod;
	}
	for(int i=0; i<MAX; i++){
		modinv[i] = binpow(fact[i], mod-2, mod);
	}

	// print(fact, 10);
	// print(modinv, 10);

	while(t--){
		int n;
		cin >> n;
		int arr[n], index[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
			index[arr[i]] = i;
		}

		int lptr = index[0], rptr = index[0];
		int done[n] = {0};
		done[0] = 1;
		int doneptr = 1;


		int curmex = 1;
		int empty = 0;
		int ans = 1;
		for(int i=1; i<n;){
			if(index[i] > index[0]){
				while(rptr != index[i]){
					rptr++;
					done[arr[rptr]] = 1;
					empty++;
				}
				empty--;
			}
			else{
				while(lptr != index[i]){
					lptr--;
					done[arr[lptr]] = 1;
					empty++;
				}
				empty--;
			}
			while(doneptr != n && done[doneptr] == 1)
				doneptr++;

			int assign = doneptr-curmex-1;
			curmex = doneptr;
			i = curmex;
			// debug(curmex, empty, assign, doneptr);
			ans *= C(empty, assign)*fact[assign] % mod;
			ans %= mod;
			empty -= assign;
		}
		cout << ans << "\n";
	}
}

