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
		int n, k;
		cin >> n >> k;

		if(k == 1){
			cout << "YES\n";
			for(int i=1; i<=n; i++){
				cout << i << "\n";
			}
			continue;
		}

		if(n%2 == 1){
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";

		int counter = 2;
		for(int i=0; i<n/2; i++){
			for(int j=0; j<k; j++){
				cout << counter << " ";
				counter += 2;
			}
			cout << "\n";
		}

		counter = 1;
		for(int i=0; i<n/2; i++){
			for(int j=0; j<k; j++){
				cout << counter << " ";
				counter += 2;
			}
			cout << "\n";
		}

	}
}
