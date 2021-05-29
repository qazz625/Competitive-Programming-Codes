#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

#define MAX 4000015

typedef long long ll;

int sieve[MAX];
int anstest[MAX];
vector<int> factors[MAX];
int totient[MAX];
ll twopow[MAX];
int calcthis[MAX];
//factors[i] stores factors of 4*i + 1

void generate_factors(int ind, vector<pair<int, int>> &v, int num, int prod){
	if(ind == v.size()){
		factors[num].push_back(prod);
		calcthis[prod] = 1;
		return;
	}

	for(int i=0; i<=v[ind].second; i++){
		generate_factors(ind+1, v, num, prod);
		prod *= v[ind].first;
	}
}



long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int find(int n, int rem, int m){
	//number of x from 1 to n such that x%m = rem
	if(rem == 0)
		return n/m;
	else
		return (n-rem+1)/m + 1;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0; i<MAX; i++){
		totient[i] = i;
	}

	totient[0] = 0;
	totient[1] = 1;

	for(int i=2; i<MAX; i++){
		if(sieve[i] == 0){
			for(int j=i; j<MAX; j+=i){
				sieve[j] = i;
				totient[j] -= totient[j]/i;
			}
		}
	}	

	for(int i=0; 4*i+1<MAX; i++){
		vector<pair<int, int>> v;
		factors[4*i+1].reserve(16);
		int num = 4*i+1;
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
		generate_factors(0, v, 4*i+1, 1);
	}
	factors[1] = {1};

	for(int i=1; i<MAX; i+=2){
		if(calcthis[i] == 1){
			twopow[i] = binpow(2, totient[i]-1, i);
		}
	}

	for(int k=1; k<=1000000; k++){
		int ans = 0;
		vector<int> ansarr(factors[4*k+1].size());
		for(int i=factors[4*k+1].size()-1; i>=0; i--){
			int f = factors[4*k+1][i];
			int x = (f-1)*twopow[f] % f;
			int curans = find(2*k, x, f);
			for(int j=i+1; j<factors[4*k+1].size(); j++){
				if(factors[4*k+1][j] % factors[4*k+1][i] == 0){
					curans -= ansarr[j];
				}
			}
			ansarr[i] = curans;
			ans += ansarr[i] * factors[4*k+1][i];
		}
		anstest[k] = ans;
	}


	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		cout << anstest[k] << "\n";
	}
}

