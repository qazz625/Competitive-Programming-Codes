#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int mod = 1000000007;
int factorial[10000];
int modinv[10000];

int binpow(int a, int b){
	if(b == 0)
		return 1;
	int x = binpow(a, b/2);
	x *= x;
	x %= mod;
	if(b%2 == 0)
		return x;
	else
		return x*a % mod;
}

int32_t main(){

	factorial[0] = 1;
	for(int i=1; i<10000; i++)
		factorial[i] = factorial[i-1]*i % mod;
	for(int i=0; i<10000; i++)
		modinv[i] = binpow(factorial[i], mod-2);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int arr[n];
		int freq[n+1] = {0};
		for(int i=0; i<n; i++){
			cin >> arr[i];
			freq[arr[i]]++;
		}

		sort(arr, arr+n, greater<int>());

		int total = 0;
		set<int> s;
		for(int i=0; i<k; i++){
			s.insert(arr[i]);
			total += arr[i];
		}

		int num = freq[*s.begin()];
		s.erase(s.begin());
		for(auto x: s)
			k -= freq[x];

		int numerator = factorial[num];
		int denominator = modinv[k] * modinv[num-k] % mod;

		cout << numerator * denominator % mod << "\n";
	}
}