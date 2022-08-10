#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int pref[100010][3];

int find(int l, int r, char c){
	if(l == 0)
		return pref[r][c-'a'];
	else
		return pref[r][c-'a'] - pref[l-1][c-'a'];
}


int32_t main(){
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		s += 'c';
		t += 'c';
		n++;

		int as=0, bs=0, at=0, bt=0;
		for(int i=0; i<n; i++){
			if(s[i] == 'a')
				as++;
			else if(s[i] == 'b')
				bs++;
			if(t[i] == 'a')
				at++;
			else if(t[i] == 'b')
				bt++;
		}

		if(as != at || bs != bt){
			cout << "NO\n";
			continue;
		}


		pref[0][0] = 0;
		pref[0][1] = 0;
		pref[0][2] = 0;

		pref[0][s[0]-'a']++;

		for(int i=1; i<n; i++){
			for(int j=0; j<3; j++)
				pref[i][j] = pref[i-1][j];
			pref[i][s[i]-'a']++;
		}

		vector<int> asind, atind, csind, ctind;
		vector<int> bsind, btind;

		csind.push_back(-1);
		ctind.push_back(-1);

		for(int i=0; i<n; i++){
			if(s[i] == 'a')
				asind.push_back(i);
			if(t[i] == 'a')
				atind.push_back(i);
			if(s[i] == 'c')
				csind.push_back(i);
			if(t[i] == 'c')
				ctind.push_back(i);
			if(s[i] == 'b')
				bsind.push_back(i);
			if(t[i] == 'b')
				btind.push_back(i);
		}

		int flag = 0;

		vector<int> ascount, atcount;
		for(int i=0; i<csind.size()-1; i++){
			int start = csind[i]+1;
			int end = csind[i+1]-1;
			int count = 0;
			for(int j=start; j<=end; j++){
				if(s[j] == 'a')
					count++;
			}
			ascount.push_back(count);
		}

		for(int i=0; i<ctind.size()-1; i++){
			int start = ctind[i]+1;
			int end = ctind[i+1]-1;
			int count = 0;
			for(int j=start; j<=end; j++){
				if(s[j] == 'a')
					count++;
			}
			atcount.push_back(count);
		}
		// for(int i=0; i<asind.size(); i++){
		// 	if(atind[i] < asind[i]){
		// 		flag = 1;
		// 	}
		// 	else{
		// 		int cval = find(asind[i], atind[i], 'c');
		// 		if(cval != 0)
		// 			flag = 1;
		// 	}
		// }

		// for(int i=0; i<csind.size(); i++){
		// 	if(ctind[i] > csind[i]){
		// 		flag = 1;
		// 	}
		// 	else{
		// 		int aval = find(ctind[i], csind[i], 'a');
		// 		if(aval != 0)
		// 			flag = 1;
		// 	}
		// }


		// debug(s);

		// print(bsind);
		// print(btind);
		// print(asind);
		// print(atind);
		print(csind);
		print(ctind);
		if(ascount == atcount){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}

