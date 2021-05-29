#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	int arr[n];
	int freq[51];
	for(int i=0; i<51; i++)
		freq[i] = 999999;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		freq[arr[i]] = min(freq[arr[i]], i);
	}

	// print(freq, 10);

	while(q--){
		int t;
		cin >> t;
		cout << freq[t]+1 << " ";
		for(int i=0; i<51; i++){
			if(i != t && freq[i] < freq[t]){
				freq[i] += 1;
			}
		}
		freq[t] = 0;
	}



}
