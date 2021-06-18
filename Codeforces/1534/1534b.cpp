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
		vector<int> arr(n+2);
		for(int i=1; i<=n; i++){
			cin >> arr[i];
		}
		int cost = 0;
		for(int i=1; i<=n; i++){
			if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
				cost += arr[i]-max(arr[i-1], arr[i+1]);
				arr[i] = max(arr[i-1], arr[i+1]);
			}
		}

		// debug(cost);
		// print(arr);

		for(int i=1; i<=n+1; i++){
			cost += abs(arr[i]-arr[i-1]);
		}
		cout << cost << "\n";
	}
}
