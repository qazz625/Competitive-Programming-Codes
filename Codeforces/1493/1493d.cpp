#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int mod = 1000000007;


int power(int a, int b){
	if(b == 0)
		return 1;
	int x = power(a, b/2);
	x = x*x % mod;

	if(b%2 == 0)
		return x;
	else
		return x*a%mod;
}


int primefactor[200010];
int zeroes[200010];


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	map<int, multiset<int>> mp;
	for(int i=2; i<200010; i++){
		if(primefactor[i] != 0)
			continue;
		for(int j=i; j<200010; j+=i)
			primefactor[j] = i;
	}

	map<int, int> arr[n];
	for(int i=0; i<n; i++){
		map<int, int> pfactors;
		zeroes[2] += 1;

		int x;
		cin >> x;
		while(x != 1){
			pfactors[primefactor[x]]++;
			x /= primefactor[x];
		}

		for(auto x: pfactors){
			mp[x.first].insert(x.second);
			zeroes[x.first] -= 1;
			zeroes[x.first+1] += 1;
		}
		arr[i] = pfactors;
	}

	for(int i=1; i<200010; i++){
		zeroes[i] += zeroes[i-1];
	}

	int gcd = 1;
	for(auto x: mp){
		int expo;
		if(zeroes[x.first] == 0)
			expo = *(x.second.begin());
		else
			expo = 0;
		gcd *= power(x.first, expo);
		gcd %= mod;
	}


	while(q--){
		int ind, num;
		cin >> ind >> num;
		ind--;

		map<int, int> pfactors;
		while(num != 1){
			pfactors[primefactor[num]]++;
			num /= primefactor[num];
		}

		for(auto x: pfactors){
			if(arr[ind].find(x.first) == arr[ind].end()){
				zeroes[x.first]--;
				mp[x.first].insert(x.second);
				arr[ind][x.first] = x.second;
				if(zeroes[x.first] == 0)
					gcd *= power(x.first, *(mp[x.first].begin()));
				gcd %= mod;
			}
			else{
				int ini = *(mp[x.first].begin());
				// debug(ini);
				mp[x.first].erase(mp[x.first].find(arr[ind][x.first]));
				mp[x.first].insert(arr[ind][x.first]+x.second);
				arr[ind][x.first] += x.second;
				int fin = *(mp[x.first].begin());
				if(zeroes[x.first] == 0)
					gcd *= power(x.first, fin-ini);
				
				gcd %= mod;

			}
		}
		cout << gcd << "\n";
	}
}
