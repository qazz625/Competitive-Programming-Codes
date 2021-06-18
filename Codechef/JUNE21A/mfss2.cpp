#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int mod = 1000000007;
int mult = 998244353;
int inf = 1e18;
int n;
int powers[100010];
int modinv[100010];


int solve(int len, int arr[]){
	int cur = 0, sum = 0;
	map<int, pair<int, int>> mp;
	for(int i=0; i<len; i++){
		cur *= mult;
		cur += arr[i];
		cur %= mod;
		sum += arr[i];
	}

	mp[cur].first = sum;
	mp[cur].second++;

	for(int i=len; i<n; i++){
		cur -= arr[i-len]*powers[len-1]%mod;
		cur *= mult;
		cur += arr[i];
		cur %= mod;
		sum -= arr[i-len];
		sum += arr[i];

		mp[cur].first = sum;
		mp[cur].second++;
	}

	int ans = -inf;
	for(auto x: mp){
		ans = max(ans, x.second.first * x.second.second);
	}
	return ans;
}

int binpow(int a, int b, int m){
	if(b == 0)
		return 1;

	int x = binpow(a, b/2, m);
	x = x*x%m;
	if(b%2 == 0)
		return x;
	return x*a%m;
}

int32_t main(){
	int t;
	cin >> t;

	powers[0] = 1;
	for(int i=1; i<100010; i++){
		powers[i] = powers[i-1]*mult%mod;
	}

	for(int i=0; i<100010; i++){
		modinv[i] = binpow(powers[i], mod-2, mod);
	}

	// print(powers, 10);
	// print(modinv, 10);

	while(t--){
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		int s = 1, e = n, ans = -inf;
		while(s <= e){
			int diff = (e-s)/3;
			int m1 = s + diff;
			int m2 = e - diff;

			int one = solve(m1, arr);
			int two = solve(m2, arr);

			debug(m1, m2, one, two);

			if(one > two){
				ans = one;
				e = m2-1;
			}
			else{
				ans = two;
				s = m1+1;
			}
		}
		cout << ans << "\n";
	}


}
