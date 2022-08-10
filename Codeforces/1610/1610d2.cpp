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

int twopow[200010];
int mod = 1000000007;

int32_t main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int even = 0;
	int fe = 0;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}


	twopow[0] = 1;
	for(int i=1; i<200010; i++){
		twopow[i] = twopow[i-1]*2 % mod;
	}

	vector<int> arr2(n, 0);
	for(int i=0; i<31; i++){
		for(int j=0; j<n; j++){
			if((arr[j] - (1ll<<i)) % (1ll<<(i+1)) == 0 && arr[j]%2 != 1){
				arr2[j] = i;
			}
		}
	}

	print(arr2);

	int freq[31] = {0};
	for(int i=0; i<n; i++){
		freq[arr2[i]]++;
	}

	print(freq, 31);

	int ans = 1;
	for(int i=1; i<31; i++){
		ans *= (1+freq[i]);
		ans %= mod;
	}
	ans--;

	debug(ans);




	// int first = twopow[n]-1;
	// int second = twopow[even]-1;
	// int third;
	// if(fe == 0){
	// 	third = 0;
	// }
	// else{
	// 	third = (even-fe)*twopow[fe-1];
	// }

	// debug(first, second, third);

	// cout << first - second + third << "\n";

}

//Read the stuff at the top