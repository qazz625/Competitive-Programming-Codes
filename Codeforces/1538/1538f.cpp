#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int dp[15][2];

int solve(int pos, int lesser, string &num){
	if(pos >= num.size())
		return 0;

	// debug(pos, lesser);

	int lim;
	if(lesser == 0)
		lim = num[pos]-'0';
	else
		lim = 9;

	if(lesser == 1){
		if(dp[pos][1] == 0){
			for(int i=0; i<=lim; i++){
				dp[pos][1] += solve(pos+1, 1, num) + (num.size()-pos);
			}
			dp[pos][1] -= num.size()-pos;
		}
	}
	else{
		if(dp[pos][0] == 0){
			for(int i=0; i<lim; i++){
				// debug(pos, lesser);
				dp[pos][0] += solve(pos+1, 1, num) + (num.size()-pos);
			}
			dp[pos][0] += solve(pos+1, 0, num);
			// dp[pos][0]--;
		}
	}

	return dp[pos][lesser];

}


int32_t main(){
	int t;
	cin >> t;
	while(t--){

		for(int i=0; i<15; i++){
			dp[i][0] = 0;
			dp[i][1] = 0;
		}

		string a, b;
		cin >> a >> b;
		int one = solve(0, 0, a);

		for(int i=0; i<15; i++){
			dp[i][0] = 0;
			dp[i][1] = 0;
		}

		int two = solve(0, 0, b);

		// debug(one, two);
		cout << two-one << "\n";
	}


}
