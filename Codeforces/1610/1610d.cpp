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
	int arr[n];
	int even = 0;
	int fe = 0;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		arr[i] %= 4;
		if(arr[i]%2 == 0)
			even++;
		if(arr[i]%4 == 2)
			fe++;
	}

	twopow[0] = 1;
	for(int i=1; i<200010; i++){
		twopow[i] = twopow[i-1]*2 % mod;
	}

	int first = twopow[n]-1;
	int second = twopow[even]-1;
	int third;
	if(fe == 0){
		third = 0;
	}
	else{
		third = (even-fe)*twopow[fe-1];
	}

	debug(first, second, third);

	cout << first - second + third << "\n";







}

//Read the stuff at the top