#include <bits/stdc++.h>
using namespace std;


int MAX = 20000040;
int sieve[20000040];


vector<int> factorize(int num){
	vector<int> ret;
	for(int i=1; i*i<=num; i++){
		if(num%i == 0){
			if(i == num/i){
				ret.push_back(i);
			}
			else{
				ret.push_back(i);
				ret.push_back(num/i);
			}
		}
	}
	return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for(int i=2; i<MAX; i++){
		if(sieve[i] != 0)
			continue;
		for(int j=i; j<MAX; j+=i)
			sieve[j] = i;
	}


	while(t--){
		int c, d, x;
		cin >> c >> d >> x;

		int ans = 0;

		vector<int> xfactors = factorize(x);
		// print(factors);
		for(auto i: xfactors){
			__int128 num = (__int128)i*(x+(long long)d*i);
			if(num%c != 0)
				continue;

			num /= c;

			if(num%((long long)i*i) != 0)
				continue;

			
			num /= (long long)i*i;

			int prev = -1, count = 0;
			while(num != 1){
				if(sieve[num] != prev)
					count++;
				prev = sieve[num];
				num /= sieve[num];
			}

			int tot = 1ll<<count;

			ans += tot;
		}
		cout << ans << "\n";
	}
}