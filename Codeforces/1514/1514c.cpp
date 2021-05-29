/*
THINGS TO DO
1) Check integer overflows
2) Check corner cases
3) Compile and run once on terminal
4) Code smart, not quick
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


set<int> fact(int n){
	set<int> s;
	for(int i=2; i <= n; i++){
		if(n%i == 0){
			s.insert(i);
			while(n%i == 0)
				n /= i;
		}
	}
	return s;
}

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

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        // q is quotient
        int q = a / m;
        int t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}


int32_t main(){
	int t = 1;
	for(int tt=0; tt<t; tt++){
		int n;
		// debug(tt);
		cin >> n;
		// n = tt;
		int arr[n] = {0};


		set<int> pfact = fact(n);
		for(auto x: pfact){
			for(int i=x; i<n; i+=x)
				arr[i] = 1;
		}

		int prod = 1;
		vector<int> v;
		for(int i=1; i<n; i++){
			if(arr[i] == 0){
				prod *= i;
				prod %= n;
				v.push_back(i);
			}
		}
		if(prod == 1){
			cout << v.size() << "\n";
			for(auto x: v){
				cout << x << " ";
			}
			cout << "\n";
			continue;
		}

		// debug(prod);

		int flag = 0;
		for(auto x: v){
			if(prod * modInverse(x, n) % n == 1){
				flag = x;
				break;
			}
		}

		cout << v.size()-1 << "\n";
		for(auto x: v){
			if(x != flag)
				cout << x << " ";
		}
		cout << "\n";
	}


	

}

//Read the stuff at the top