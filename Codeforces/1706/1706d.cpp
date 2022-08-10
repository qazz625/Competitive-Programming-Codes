#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n, k;

int check(int upper, int arr[]){
	int lower = 1<<30;
	int cur = 1;
	for(int i=0; i<n; i++){
		while(cur != k+1){
			int temp = arr[i]/cur;
			if(temp <= upper){
				lower = min(lower, temp);
				break;
			}
			else{
				cur++;
			}
		}

		if(cur == k+1){
			lower = 1<<30;
			break;
		}
	}
	return lower;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		int arr[n];
		int maxlim = 0;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			maxlim = max(maxlim, arr[i]);
		}

		int res = 1<<30;
		for(int i=0; i<=maxlim; i++){
			int c = check(i, arr);
			if(c != 1<<30)
				res = min(res, i-c);
		}

		cout << res << "\n";
	}
}
