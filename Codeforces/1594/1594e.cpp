#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int k;
int n;
int mod = 1000000007;

int binpow(int a, int b, int mod){
	if(b == 0)
		return 1;
	int x = binpow(a, b/2, mod);
	x = x*x % mod;
	if(b%2 == 0)
		return x;
	else
		return x*a % mod;
}

map<pair<int, int>, int> dp;

void solve(int v, set<int> &consider, map<int, int> &colours, int level){
	if( (1ll<<(k-1)) <= v && consider.find(v) != consider.end() ){
		for(int i=0; i<6; i++){
			dp[{v, i}] = 0;
		}
		dp[{v, colours[v]}] = 1;
		return;
	}

	if(consider.find(v) == consider.end()){
		for(int i=0; i<6; i++){
			dp[{v, i}] = binpow(4, (1ll<<(k-level))-2, mod);
		}
		return;
	}

	solve(2*v, consider, colours, level+1);
	solve(2*v+1, consider, colours, level+1);

	// debug(v);

	if(colours.find(v) != colours.end()){
		int c = colours[v];
		for(int i=0; i<6; i++)
			dp[{v, i}] = 0;

		int temparr[6] = {0};
		for(int i=0; i<6; i++){
			int one = dp[{2*v, i}];
			for(int j=0; j<6; j++){
				if(c-(c%2) != i-(i%2) && c-(c%2) != j-(j%2)){
					temparr[c] += one * dp[{2*v+1, j}] % mod;
				}
			}
		}

		for(int i=0; i<6; i++){
			dp[{v, i}] = temparr[i]%mod;
		}
	}

	else{
		for(int k=0; k<6; k++){

			int temparr[6] = {0};
			for(int i=0; i<6; i++){
				int one = dp[{2*v, i}];
				for(int j=0; j<6; j++){
					if(k-(k%2) != i-(i%2) && k-(k%2) != j-(j%2)){
						temparr[k] += one * dp[{2*v+1, j}] % mod;
					}
				}
			}
			dp[{v, k}] = temparr[k]%mod;
		}
	}



}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	dp.clear();

	cin >> k;
	cin >> n;

	pair<int, string> arr[n];
	map<int, int> colours;
	for(int i=0; i<n; i++){
		int v;
		string s;
		cin >> v >> s;
		arr[i] = {v, s};
		if(s == "white")
			colours[v] = 0;
		else if(s == "yellow")
			colours[v] = 1;
		else if(s == "green")
			colours[v] = 2;
		else if(s == "blue")
			colours[v] = 3;
		else if(s == "red")
			colours[v] = 4;
		else if(s == "orange")
			colours[v] = 5;
	}

	set<int> consider;

	for(int i=0; i<n; i++){
		int num = arr[i].first;
		while(num != 0){
			consider.insert(num);
			num /= 2;
		}
	}

	// print(consider);

	solve(1, consider, colours, 0);

	// for(auto x: dp){
	// 	print(x.first);
	// 	debug(x.second);
	// 	cout << "\n";
	// }

	int ans = 0;
	for(int i=0; i<6; i++){
		ans += dp[{1, i}];
	}

	cout << ans%mod << "\n";
}
