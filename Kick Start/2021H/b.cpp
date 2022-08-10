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
		int n;
		cin >> n;
		string s;
		cin >> s;

		//yellow
		int count1 = 0;
		int seqlen = 0;
		for(int i=0; i<n; i++){
			if(s[i] != 'P' && s[i] != 'B' && s[i] != 'R' && s[i] != 'U'){
				seqlen++;
			}
			else{
				if(seqlen != 0){
					count1++;
					seqlen = 0;
				}
			}
		}
		if(seqlen != 0){
			count1++;
			seqlen = 0;
		}

		//red
		int count2 = 0;
		for(int i=0; i<n; i++){
			if(s[i] != 'G' && s[i] != 'B' && s[i] != 'Y' && s[i] != 'U'){
				seqlen++;
			}
			else{
				if(seqlen != 0){
					count2++;
					seqlen = 0;
				}
			}
		}
		if(seqlen != 0){
			count2++;
			seqlen = 0;
		}

		//blue
		int count3 = 0;
		for(int i=0; i<n; i++){
			if(s[i] != 'O' && s[i] != 'R' && s[i] != 'Y' && s[i] != 'U'){
				seqlen++;
			}
			else{
				if(seqlen != 0){
					count3++;
					seqlen = 0;
				}
			}
		}
		if(seqlen != 0){
			count3++;
			seqlen = 0;
		}

		// debug(count1, count2, count3, tt);

		cout << "Case #" << tt+1 << ": " << count1+count2+count3 << "\n";
	}
}

