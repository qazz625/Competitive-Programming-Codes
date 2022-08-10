
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
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		int flag = 0;
		int g = 0;
		for(int i=0; i<40; i++){
			int count = 0;
			for(int j=0; j<n; j++){
				if(arr[j] & (1ll<<i))
					count++;
			}

			g = __gcd(count, g);
		}

		if(g == 0){
			for(int i=1; i<=n; i++){
				cout << i << " ";
			}
			cout << "\n";
			continue;
		}
		else{
			set<int> ans;
			for(int i=1; i*i<=g; i++){
				if(g%i == 0){
					ans.insert(i);
					ans.insert(g/i);
				}
			}

			for(auto x: ans){
				cout << x << " ";
			}
			cout << "\n";
		}
	}


}

//Read the stuff at the top