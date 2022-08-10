#include <bits/stdc++.h>
using namespace std;

#define int long long

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
		reverse(s.begin(), s.end());

		if(n == 1){
			cout << (s[0]-'0') - 1 << "\n";
			continue;
		}

		int dp[n+2][2] = {0};

		//0 for without carry
		//1 for with carry

		dp[0][0] = (s[0]-'0')+1;
		dp[1][0] = (s[1]-'0')+1;
		dp[0][1] = 9 - (s[0]-'0');
		dp[1][1] = 9 - (s[1]-'0');


		for(int i=2; i<n; i++){
			dp[i][0] = dp[i-2][0]*( (s[i]-'0')+1 );
			if(s[i] != '0')
				dp[i][0] += dp[i-2][1]*( (s[i]-'0') );

			dp[i][1] = dp[i-2][0]*( 9 - (s[i]-'0') );
			dp[i][1] += dp[i-2][1]*( 10 - (s[i]-'0') );

		} 

		// for(int i=0; i<n; i++){
		// 	cout << dp[i][0] << " " << dp[i][1] << "\n";
		// }
		// cout << "\n";

		cout << dp[n-1][0] * dp[n-2][0] - 2 << "\n";


	}


}

//Read the stuff at the top