#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;

	int ind1 = 0, ind2 = 0;

	vector<int> dp1(m, -1);
	while(ind2 != m){
		if(s[ind1] == t[ind2]){
			dp1[ind2] = ind1;
			ind1++;
			ind2++;
		}
		else{
			dp1[ind2] = dp1[ind2-1];
			ind1++;
		}
	}

	vector<int> dp2(m, -1);
	ind1 = n-1, ind2 = m-1;
	while(ind2 != -1){
		if(s[ind1] == t[ind2]){
			dp2[ind2] = ind1;
			ind1--;
			ind2--;
		}
		else{
			dp2[ind2] = dp2[ind2+1];
			ind1--;
		}
	}

	// print(dp1);
	// print(dp2);

	int ans = -1;
	for(int i=0; i<m-1; i++){
		ans = max(ans, dp2[i+1]-dp1[i]);
	}
	cout << ans << "\n";
}

