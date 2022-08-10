#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

#define MAX 300010

int sieve[MAX];

int32_t main(){
	int t;
	cin >> t;

	for(int i=2; i<MAX; i++){
		if(sieve[i] == 0){
			for(int j=2*i; j<MAX; j+=i)
				sieve[j] = 1;
		}
	}

	// print(sieve, 30);

	// print(primes);


	while(t--){
		int n;
		char c;
		cin >> n >> c;
		string s;
		cin >> s;

		if(count(s.begin(), s.end(), c) == n){
			cout << "0\n";
			continue;
		}


		int flag = -1;
		for(int i=1; i<n; i++){
			flag = i+1;
			for(int j=i; j<n; j+=i+1){
				if(s[j] != c)
					flag = -1;
			}
			if(flag != -1)
				break;
		}


		if(flag != -1){
			cout << 1 << "\n" << flag << "\n";
			continue;
		}

		cout << "2\n";

		for(int i=n; i>=1; i--){
			if(sieve[i] == 0){
				cout << i << " " << 2 << "\n";
				break;
			}
		}


	}


}
