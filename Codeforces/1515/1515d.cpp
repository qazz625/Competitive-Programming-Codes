#include <bits/stdc++.h>
using namespace std;

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
		int n, l, r;
		cin >> n >> l >> r;
		int left[n+1]={0}, right[n+1]={0};
		for(int i=0; i<l; i++){
			int x;
			cin >> x;
			left[x]++;
		}

		for(int i=0; i<r; i++){
			int x;
			cin >> x;
			right[x]++;
		}

		for(int i=0; i<=n; i++){
			int mi = min(left[i], right[i]);
			left[i] -= mi;
			right[i] -= mi;
		}

		int lefttot1=0, righttot1 = 0;
		for(int i=0; i<=n; i++){
			lefttot1 += left[i];
			righttot1 += right[i];
		}

		if(lefttot1 >= righttot1){
			int ans = 0;
			for(int i=0; i<=n; i++){
				ans += left[i]/2;
				left[i] %= 2;
			}

			int lefttot=0;
			for(int i=0; i<=n; i++){
				lefttot += left[i];
			}

			if(lefttot <= righttot1){
				// debug("AA");
				cout << (lefttot1-righttot1)/2 + righttot1;
			}
			else{
				// debug("BB");
				cout << ans + (lefttot-righttot1) + righttot1;
			}
			cout << "\n";

		}
		else{
			int ans = 0;
			for(int i=0; i<=n; i++){
				ans += right[i]/2;
				right[i] %= 2;
			}

			int righttot = 0;
			for(int i=0; i<=n; i++){
				righttot += right[i];
			}

			// debug(lefttot1, righttot);

			if(righttot <= lefttot1){
				// debug("CC");
				cout << (righttot1-lefttot1)/2 + lefttot1;
			}
			else{
				// debug("DD");
				cout << ans + (righttot-lefttot1) + lefttot1;
			}
			cout << "\n";
		}
		
	}
}
