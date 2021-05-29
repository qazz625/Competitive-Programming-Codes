#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int a = 998244353;
int mod1 = 1000000007;

int b = 998244351;
int mod2 = 1000000009;

int apow[30], bpow[30];

int binpow(int a, int b, int mod){
	if(b == 0)
		return 1;
	int x = binpow(a, b/2, mod);
	x = x*x % mod;

	if(b%2 == 0)
		return x;
	else
		return x*a%mod;
}

int mp[20010][26];

int32_t main(){
	for(int i=0; i<30; i++){
		apow[i] = binpow(a, i, mod1);
		bpow[i] = binpow(b, i, mod2);
	}

	// print(apow, 10);
	// print(invapow, 10);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int, int>> arr(n);
		vector<string> strarr(n);
		set<pair<int, int>> se;

		for(int i=0; i<n; i++)
			for(int j =0; j<26; j++)
				mp[i][j] = 0;

		for(int i=0; i<n; i++){
			string s;
			cin >> s;
			strarr[i] = s;
			int cur1 = 0, cur2 = 0;
			for(int j=0; j<s.size(); j++){
				cur1 += s[j] * apow[j] % mod1;
				cur2 += s[j] * bpow[j] % mod2;
			}
			cur1 %= mod1;
			cur2 %= mod2;

			arr[i] = {cur1, cur2};
			se.insert({cur1, cur2});
		}

		for(int i=0; i<n; i++){
			int cur1 = arr[i].first;
			int cur2 = arr[i].second;
			cur1 -= strarr[i][0];
			cur2 -= strarr[i][0];

			if(cur1 < 0)
				cur1 += mod1;
			if(cur2 < 0)
				cur2 += mod2;

			for(char j='a'; j<='z'; j++){
				pair<int, int> temp = {(cur1+j)%mod1, (cur2+j)%mod2};
				if(se.find(temp) != se.end())
					mp[i][j-'a'] = 1;
			}
		}

		assert(se.size() == n);

		// for(int i=0; i<n; i++){
		// 	for(int j=0; j<26; j++){
		// 		cout << mp[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }

		int ans = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(mp[i][strarr[j][0]-'a'] == 0 && mp[j][strarr[i][0]-'a'] == 0){
					ans++;
				}
			}
		}
		cout << ans*2 << "\n";	
	}
}