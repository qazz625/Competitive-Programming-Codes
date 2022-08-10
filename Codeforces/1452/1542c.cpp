#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int lcm(int a, int b){
	return a*b/__gcd(a, b);
}

int mod = 1000000007;


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int curlcm = 1;
		int ans = 0;
		for(int i=1; i<50; i++){
			ans += i * (n/curlcm - n/lcm(curlcm, i)) % mod;
			curlcm = lcm(curlcm, i);
			if(curlcm > n)
				break;
		}
		cout << ans%mod << "\n";
	}	


}

