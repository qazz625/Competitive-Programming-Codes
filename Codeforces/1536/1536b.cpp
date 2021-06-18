#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int isSubstr(string &cur, string &s){
	int l = cur.size();
	// debug(cur, s);
	for(int i=0; i<s.size()-l+1; i++){
		string temp;
		for(int j=i; j<i+l; j++)
			temp += s[j];
		// debug(temp, cur);
		if(temp == cur){
			return 0;
		}
	}
	return 1;
}


string ans = "~";
void solve(string &cur, string &s, int ind){
	if(ind == cur.size()){

		if(isSubstr(cur, s)){
			ans = cur;
		}
		return;
	}
	// debug(cur, ind);

	for(int i=0; i<26 && ans=="~"; i++){
		cur[ind] += i;
		solve(cur, s, ind+1);
		cur[ind] -= i;
	}
}

void check(int substrlen, string &s){
	string cur;
	for(int i=0; i<substrlen; i++)
		cur += 'a';

	solve(cur, s, 0);
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;

		ans = "~";

		for(int i=1; i<=n && ans=="~"; i++){
			check(i, s);
		}

		cout << ans << "\n";
	}


}
