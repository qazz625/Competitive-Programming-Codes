#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n, k;

int calcval(string &s){
	int tot = 0;
	for(int i=0; i<n-1; i++){
		tot += 10*(s[i]-'0') + (s[i+1]-'0');
	}
	return tot;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		string s;
		cin >> s;

		int onecount = 0;
		int totvalue = 0;
		int oneloc = -1;
		int l=-1, r=-1;

		for(int i=n-1; i>=0; i--){
			if(s[i] == '1'){
				if(onecount == 0)
					r = i;
				onecount++;
				oneloc = i;
				l = i;

			}
			if(i != n-1){
				totvalue += 10*(s[i]-'0') + (s[i+1]-'0');
			}
		}
		// debug(req);
		// debug(onecount);

		if(onecount == 0){
			cout << totvalue << "\n";
			continue;
		}
		else if(onecount == 1){
			int d1 = oneloc;
			int d2 = n-1 - oneloc;
			// debug(d1, d2);
			if(d2 <= k){
				swap(s[n-1], s[oneloc]);
			}
			else if(d1 <= k){
				swap(s[0], s[oneloc]);
			}
			int ans = calcval(s);
			cout << ans << "\n";
		}
		else{
			int d1 = l;
			int d2 = n-1 - r;
			if(d1+d2 <= k){
				swap(s[0], s[l]);
				swap(s[n-1], s[r]);
			}
			else if(d2 <= k){
				swap(s[n-1], s[r]);
			}
			else if(d1 <= k){
				swap(s[0], s[l]);
			}
			int ans = calcval(s);
			cout << ans << "\n";
		}
	}
}

