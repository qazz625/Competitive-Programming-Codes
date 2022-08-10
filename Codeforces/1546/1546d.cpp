#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod = 998244353;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

#define MAX 200000


int fact[200000];
int modinv[200000];

int binpow(int a, int b, int m){
	if(b == 0)
		return 1;
	int x = binpow(a, b/2, m);
	x = x*x % m;
	if(b%2 == 0)
		return x;
	else
		return x*a % m;
}

int C(int n, int r){
	if(r > n || n < 0 || r < 0)
		return 0;

	int num = fact[n];
	int denom = modinv[r]*modinv[n-r] % mod;
	return num*denom % mod;

}

int evensolve(int even, int num){
	if(even == 0 && num == 0)
		return 1;

	num /= 2;
	return C(even+num-1, even-1);
}

int oddsolve(int odd, int num){
	if(odd == 0 && num == 0)
		return 1;

	num -= odd;
	if(num%2 != 0)
		return 0;

	num /= 2;
	return C(odd+num-1, odd-1);
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
		string s;
		cin >> s;
		s = '0' + s + '0';

		int prev = 0;
		int even = 0, odd = 0, onecount = 0;
		for(int i=1; i<=n+1; i++){
			if(s[i] == '0'){
				int num = i-prev-1;
				if(num%2 == 0)
					even++;
				else
					odd++;
				prev = i;
			}
			else{
				onecount++;
			}
		}

		// debug(even, odd, onecount);

		int ans = 0;
		for(int i=0; i<=onecount; i+=2){
			int one = evensolve(even, i);
			int two = oddsolve(odd, onecount-i);
			ans += one*two;
			ans %= mod;
		}
		cout << ans << "\n";
	}
}
