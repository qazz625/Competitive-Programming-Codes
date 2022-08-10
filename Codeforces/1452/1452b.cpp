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
		int n, a, b;
		cin >> n >> a >> b;

		if(a == 1){
			if((n-1)%b == 0)
				cout << "Yes\n";
			else
				cout << "No\n";
			continue;
		}

		string ans = "No";
		for(int cur = 1; cur <= n; cur *= a){
			if((n-cur)%b == 0)
				ans = "Yes";
		}
		cout << ans << "\n";
	}
}

