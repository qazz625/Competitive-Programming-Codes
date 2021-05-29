#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int n;
	cin >> n;
	set<pair<int, string>> se;
	for(int i=0; i<n; i++){
		string s;
		int t;
		cin >> s >> t;
		se.insert({-t, s});
	}

	auto itr = ++se.begin();
	cout << itr->second << "\n";




}

//Read the stuff at the top