#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int binpow(int a, int b, int mod){
	if(b == 0)
		return 1;

	int x = binpow(a, b/2, mod);
	x = x*x%mod;

	if(b%2 == 0)
		return x;
	else
		return x*a % mod;
}

int prime = 998244353;
int mod = 1000000007;

int primepowers[200000];
int32_t main(){
	int t;
	cin >> t;
	primepowers[0] = 1;
	for(int i=1; i<200000; i++){
		primepowers[i] = primepowers[i-1]*prime % mod; 
	}
	int inverse = binpow(prime, mod-2, mod);
	while(t--){
		int n;
		string s;
		cin >> n >> s;

		int cur = 0;
		for(int i=0; i<n/2; i++){
			cur += ((s[i]-'0')+3)*primepowers[i];
			cur %= mod;
		}
		map<int, vector<pair<int, int>>> hashes;

		hashes[cur].push_back({0, n/2-1});

		for(int i=n/2; i<n; i++){
			cur -= ((s[i-n/2]-'0')+3);
			cur *= inverse;
			cur += ((s[i]-'0')+3)*primepowers[n/2-1];
			cur = (cur%mod + mod)%mod;
			hashes[cur].push_back({i-n/2+1, i});
		}

		// for(auto x: hashes){
		// 	debug(x.first);
		// 	print(x.second);
		// 	cout << endl;
		// }
		// debug("AA");

		int flag = 0;
		for(auto x: hashes){
			if(x.second.size() > 1){
				flag = 1;
				pair<int, int> p1 = x.second[0], p2 = x.second[1];
				cout << p1.first+1 << " " << p1.second+1 << " " << p2.first+1 << " " << p2.second+1 << "\n";
			}
		}

		if(flag == 1)
			continue;

		debug("AA");

	}


}

//Read the stuff at the top