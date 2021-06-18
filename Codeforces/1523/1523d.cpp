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


int32_t main(){
	int n, m, p;
	cin >> n >> m >> p;
	vector<int> arr(n);
	string extra;
	for(int i=0; i<60-m; i++){
		extra += '0';
	}
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		s = extra + s;
		int num = 0;
		for(int i=0; i<60; i++){
			num += (1ll<<i)*(s[60-1-i]-'0');
		}
		debug(num);
	}

	int s = 0, e = 15;


}

//Read the stuff at the top