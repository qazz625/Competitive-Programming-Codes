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

	int n, k, x;
	cin >> n >> k >> x;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	sort(arr, arr+n);
	// print(arr, n);

	vector<int> breaks;
	for(int i=0; i<n-1; i++){
		if(arr[i+1]-arr[i] > x){
			int p = arr[i+1]-arr[i];
			if(p%x == 0)
				p = p/x - 1;
			else
				p = p/x;
			breaks.push_back(p);
		}
	}

	sort(breaks.begin(), breaks.end());
	// print(breaks);

	int totbreaks = breaks.size();
	for(int i=0; i<breaks.size(); i++){
		if(breaks[i] <= k){
			k -= breaks[i];
			totbreaks--;
		}
	}
	cout << totbreaks+1 << "\n";
}
