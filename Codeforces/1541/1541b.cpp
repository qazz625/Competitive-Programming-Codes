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
		vector<pair<int, int>> arr(n);
		for(int i=0; i<n; i++){
			cin >> arr[i].first;
			arr[i].second = i+1;
		}
		sort(arr.begin(), arr.end());
		int ans = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(arr[i].first * arr[j].first > 2*n)
					break;
				if(arr[i].first * arr[j].first == arr[i].second + arr[j].second)
					ans++;
			}
		}
		cout << ans << "\n";
	}
}

