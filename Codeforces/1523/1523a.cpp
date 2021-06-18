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
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;

		string prev = s;
		for(int i=0; i<m; i++){
			string news = s;

			if(s[1] == '1'){
				news[0] = '1';
			}

			for(int j=1; j<n-1; j++){
				if(s[j-1] == s[j+1])
					continue;
				news[j] = '1';
			}

			if(s[n-2] == '1'){
				news[n-1] = '1';
			}

			if(s == news)
				break;

			s = news;
			// debug(news);
		}


		cout << s << "\n";
	}


}
