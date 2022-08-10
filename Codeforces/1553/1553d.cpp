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
		string s, t;
		cin >> s >> t;

		s = "~~~" + s;
		int dp[s.size()];
		for(int i=0; i<s.size(); i++)
			dp[i] = -1;

		for(int i=3; i<s.size(); i++){
			dp[i] = dp[i-2];

			int matched1 = dp[i-3];
			if(matched1+1 < t.size() && s[i] == t[matched1+1]){
				dp[i] = max(dp[i], matched1+1);
			}

			int matched2 = dp[i-1];
			if(matched2+1 < t.size() && s[i] == t[matched2+1]){
				dp[i] = max(dp[i], matched2+1);
			}
		}

		print(dp, s.size());
		string ans = "NO";
		for(int i=(int)s.size()-1; i>=(int)s.size()-3; i-=2){
			if(dp[i]+1 == t.size())
				ans = "YES";
		}

		cout << ans << "\n";
	}


}

