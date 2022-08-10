#include <bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

typedef long long ll;
ll mod = 998244353;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, K;
	cin >> n >> K;

	ll dp[n+1] = {0};
	ll ans[n+1] = {0};

	dp[0] = 1;
	ans[0] = 1;

	int curstart = 0;
	for(int i=0; i<635; i++){
		ll newdp[n+1] = {0};
		curstart += K+i;

		for(int j=0; j<K+i; j++){
			ll prev = 0;
			for(int k=j; k<=n; k+=K+i){
				if(k >= curstart)
					newdp[k] = prev;
				prev += dp[k];
			}
		}

		for(int j=0; j<=n; j++){
			dp[j] = newdp[j]%mod;
			ans[j] += newdp[j];
		}
	}
	for(int i=1; i<=n; i++)
		cout << ans[i]%mod << " ";
	cout << "\n";
}

