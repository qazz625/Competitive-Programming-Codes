#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		int open = 0, close = 0;
		for(int i=0; i<n; i++){
			if(s[i] == '(')
				open++;
			else if(s[i] == ')')
				close++;
		}

		int reqopen = n/2 - open;
		int reqclosed = n/2 - close;

		if(reqopen == 0 || reqclosed == 0){
			cout << "YES\n";
			continue;
		}

		reqopen--; reqclosed--;
		int cl = 1, op = 1;

		string dups = s;
		for(int i=0; i<n; i++){
			if(s[i] == '?'){
				if(reqopen != 0){
					dups[i] = '(';
					reqopen--;
				}
				else if(cl == 1){
					dups[i] = ')';
					cl--;
				}
				else if(op == 1){
					dups[i] = '(';
					op--;
				}
				else{
					dups[i] = ')';
					reqclosed--;
				}

			}
		}

		// debug(dups);


		int cur = 0;
		int flag = 0;
		for(int i=0; i<n; i++){
			if(dups[i] == '(')
				cur++;
			else cur--;

			if(cur < 0){
				flag = 1;
				break;
			}
		}


		if(flag == 1 || cur != 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}

