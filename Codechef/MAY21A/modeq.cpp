#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MAX 1000010
int sieve[MAX];
vector<int> primes;

vector<int> factors[MAX];

void generate_factors(int ind, vector<pair<int, int>> &v, int num, int prod){
	if(ind == v.size()){
		factors[num].push_back(prod);
		return;
	}

	for(int i=0; i<=v[ind].second; i++){
		generate_factors(ind+1, v, num, prod);
		prod *= v[ind].first;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=2; i<MAX; i++){
		if(sieve[i] == 0){
			primes.push_back(i);
			for(int j=i; j<MAX; j+=i){
				sieve[j] = i;
			}
		}
	}

	// print(primes);

	for(int i=2; i<MAX; i++){
		vector<pair<int, int>> v;
		int num = i;
		int prev = -1;
		while(num != 1){
			if(sieve[num] != prev){
				v.push_back({sieve[num], 1});
				prev = sieve[num];
			}
			else{
				v.back().second++;
			}
			num /= sieve[num];
		}
		// debug(i);
		// print(v);
		generate_factors(0, v, i, 1);
	}

	int count = 0;
	for(int i=2; i<MAX; i++){
		count += factors[i].size();
	}

	factors[1].push_back(1);

	// debug(count);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int ans = 0;
		for(int i=1; i<=n; i++){
			int num = m - m%i;
			if(num == 0){
				ans += i-1;
				continue;
			}

			int len = factors[num].size();
			for(int j=0; j<len; j++){
				int one = factors[num][j];
				int two = factors[num][len-1-j];
				// debug(one, two, num);
				if(one < i)
					ans++;
			}
			// debug(i, ans);
		}
		cout << ans << "\n";
	}

}

