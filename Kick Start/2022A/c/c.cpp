#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../../debug.cpp"
#endif

int t, n, q;
string s;

int solve(string rep){
	

	string temp = s;
	int ind = 0;
	for(int i=0; i<5; i++){
		if(temp[i] == '?'){
			temp[i] = rep[ind];
			ind++;
		}
	}

	string pal5 = temp;
	string pal6 = temp;
	int pal5valid = 1, pal6valid = 1;

	debug(pal5, pal6);

	for(int i=0; i<n-4; i++){
		string cur;
		for(int j=0; j<5; j++){
			cur += pal5[i+j];
		}

		if(cur[4] == '?' && cur[0] == '1'){
			pal5[i+4] = '0';
			cur[4] = '0';
		}
		else if(cur[4] == '?' && cur[0] == '0'){
			pal5[i+4] = '1';
			cur[4] = '0';
		}

		// debug(cur, pal);

		string revcur = cur;
		reverse(revcur.begin(), revcur.end());
		if(cur == revcur)
			pal5valid = 0;
	}

	for(int i=0; i<n-5; i++){
		string cur;
		for(int j=0; j<6; j++){
			cur += pal6[i+j];
		}

		if(cur[5] == '?' && cur[0] == '1'){
			pal6[i+5] = '0';
			cur[5] = '0';
		}
		else if(cur[5] == '?' && cur[0] == '0'){
			pal6[i+5] = '1';
			cur[5] = '1';
		}

		// debug(cur);

		string revcur = cur;
		reverse(revcur.begin(), revcur.end());
		if(cur == revcur)
			pal6valid = 0;
	}

	debug(pal5, pal6, pal5valid, pal6valid);

	if(pal5valid == 1 && pal6valid == 1 && pal5 == pal6){
		return 1;
	}
	else{
		return 0;
	}
}

int32_t main(){
	cin >> t;
	for(int tt=1; tt<=t; tt++){
		cin >> n;
		cin >> s;

		if(n < 5){
			cout << "POSSIBLE\n";
		}

		q = 0;
		for(int i=0; i<5; i++)
			if(s[i] == '?')
				q++;

		int ans = 0;
		for(int j=0; j<(1<<q); j++){
			string rep;
			for(int k=0; k<q; k++){
				if((1<<k)&j)
					rep += '0';
				else
					rep += '1';
			}
			// debug(rep);

			ans |= solve(rep);
		}


		// cout << "Case #" << tt << ": ";
		if(ans == 1)
			cout << "POSSIBLE\n";
		else
			cout << "IMPOSSIBLE\n";
		
	}
}
