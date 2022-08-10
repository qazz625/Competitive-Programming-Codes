#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

vector<int> pref[400000];

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		vector<int> cur(4);

		//0 for positive even
		//1 for positive odd
		//2 for negative even
		//3 for negative odd

		for(int i=0; i<n; i++){
			if(i%2 == 0 && s[i] == '+')
				cur[0]++;
			else if(i%2 == 1 && s[i] == '+')
				cur[1]++;
			else if(i%2 == 0 && s[i] == '-')
				cur[2]++;
			else
				cur[3]++;
			pref[i] = cur;
		}

		// for(int i=0; i<n; i++){
		// 	print(pref[i]);
		// }


		while(q--){
			int l, r;
			cin >> l >> r;
			l--; r--;
			vector<int> cur = pref[r];
			if(l != 0){
				for(int i=0; i<4; i++)
					cur[i] -= pref[l-1][i];
			}

			// print(cur);

			int netsum = (cur[0]-cur[2]) - (cur[1]-cur[3]);
			// debug(netsum);
			// if
			netsum = abs(netsum);
			if(netsum == 0){
				cout << "0\n";
			}
			else if(netsum%2 == 0){
				cout << "2\n";
			}
			else{
				cout << "1\n";
			}
		}
	}


}
