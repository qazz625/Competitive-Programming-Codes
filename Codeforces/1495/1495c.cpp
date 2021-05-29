#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> miners, diamonds;

		for(int i=0; i<2*n; i++){
			int type;
			cin >> type;
			int loc;
			cin >> loc;
			if(type == 0)
				miners.push_back(abs(loc));
			else
				diamonds.push_back(abs(type));
		}

		sort(miners.begin(), miners.end(), greater<int>());
		sort(diamonds.begin(), diamonds.end());

		// print(miners);
		// print(diamonds);

		double ans1 = 0, ans2 = 0;
		for(int i=0; i<n; i++){
			ans1 += sqrt(miners[i]*miners[i] + diamonds[i]*diamonds[i]);
			ans2 += sqrt(miners[i]*miners[i] + diamonds[n-1-i]*diamonds[n-1-i]);
		}
		
		cout << fixed << setprecision(13) << min(ans1, ans2) << "\n";
	}


}