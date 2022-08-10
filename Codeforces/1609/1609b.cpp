#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	int total = 0;
	for(int i=0; i<n-2; i++){
		string temp;
		for(int j=i; j<i+3; j++)
			temp += s[j];
		if(temp == "abc")
			total++;
	}

	s = "~~" + s + "~~";
	// debug(total);


	while(q--){
		int ind;
		char c;
		cin >> ind >> c;
		ind++;

		int add = 0, sub = 0;
		for(int i=ind-2; i<=ind; i++){
			if(s.substr(i, 3) == "abc")
				sub++;
		}
		s[ind] = c;
		for(int i=ind-2; i<=ind; i++){
			if(s.substr(i, 3) == "abc")
				add++;
		}

		total -= sub;
		total += add;

		cout << total << "\n";

	}


}

