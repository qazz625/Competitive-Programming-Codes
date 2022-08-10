#include <bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE
// 	#define _GLIBCXX_DEBUG
// 	#include "../../../debug.cpp"
// #endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++){
		string s, f;
		cin >> s >> f;
		int n = s.size();

		int mp[26] = {0};

		for(char x: f){
			mp[x-'a'] = 1;
		}

		int ans = 0;
		for(char x: s){
			int cans = 100;
			for(int j=0; j<26; j++){
				if(mp[(x-'a' + j) % 26] == 1){
					cans = min(cans, j);
				}
				if(mp[(x-'a' - j + 26) % 26] == 1){
					cans = min(cans, j);
				}
			}
			ans += cans;
		}

		cout << "Case #" << tt+1 << ": ";
		cout << ans << "\n";

	}
}

