#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int test;
	cin >> test;
	while(test--){
		string s, t;
		cin >> s >> t;
		int n = t.size();
		int ans = 1;
		for(int i=0; i<s.size(); i++){
			for(int j=i; j<s.size(); j++){
				int ptr1 = 0;
				int flag = 0;
				for(int x=i; x<=j && ptr1 != t.size(); x++){
					if(t[ptr1] == s[x])
						ptr1++;
					else
						flag = 1;
				}
				// debug(ptr1, i, j);
				// debug(j-(n-(j-i+1)), i, j);
				for(int x=j-1; x>=max(0, j-(n-(j-i+1))) && ptr1 != t.size(); x--){
					// debug(t[ptr1], s[x]);
					if(t[ptr1] == s[x])
						ptr1++;
					else
						flag = 1;
				}
				// debug(ptr1, i, j);
				if(ptr1 != t.size())
					flag = 1;

				if(flag == 0){
					cout << "YES\n";
					// debug(i, j);
					ans = 0;
					break;
				}
				// cout << "\n";
			}
			if(ans == 0)
				break;
		}
		if(ans == 1){
			cout << "NO\n";
		}
	}


}
