#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;

#define int long long

// #ifndef ONLINE_JUDGE
// 	#define _GLIBCXX_DEBUG
// 	#include "../../../debug.cpp"
// #endif


int32_t main(){
	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++){
		int n, q, p;
		cin >> n >> q >> p;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		cout << "Case #" << tt+1 << ": ";

		while(q--){
			int type;
			cin >> type;
			if(type == 1){
				int pos, val;
				cin >> pos >> val;
				pos--;
				arr[pos] = val;
			}
			else{
				int s, l, r;
				cin >> s >> l >> r;
				l--; r--;
				int ans = 0;
				for(int i=l; i<=r; i++){
					int prod1 = 1, prod2 = 1;
					for(int j=0; j<s; j++)
						prod1 *= arr[i];
					for(int j=0; j<s; j++)
						prod2 *= arr[i]%p;

					int num = prod1 - prod2;
					if(num == 0)
						continue;

					while(num%p == 0){
						ans++;
						num /= p;
					}
				}
				cout << ans << " ";
			}
		}
		cout << "\n";
	}
}
