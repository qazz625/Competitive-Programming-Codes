#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	string one;
	for(int i=0; i<n; i++){
		one += s[i];
		string two;
		for(int j=i+1; j<n; j++)
			two += s[j];
		if(one+'~' <= two+'~'){
			for(int j=0; j<k; j++){
				cout << s[j%(i+1)];
			}
			cout << "\n";
			break;
		}
	}
}
