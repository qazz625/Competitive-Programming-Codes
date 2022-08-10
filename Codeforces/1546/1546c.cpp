#include <bits/stdc++.h>
using namespace std;

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
		vector<int> arr(n);
		map<int, pair<int, int>> mp1, mp2;

		for(int i=0; i<n; i++){
			cin >> arr[i];
			if(i%2 == 0)
				mp1[arr[i]].first++;
			else
				mp1[arr[i]].second++;
		}

		sort(arr.begin(), arr.end());
		for(int i=0; i<n; i++){
			if(i%2 == 0)
				mp2[arr[i]].first++;
			else
				mp2[arr[i]].second++;
		}

		int flag = 0;
		for(auto x: mp1){
			pair<int, int> p1 = x.second;
			pair<int, int> p2 = mp2[x.first];

			if(p1.first != p2.first || p1.second != p2.second){
				flag = 1;
			}
		}
		if(flag == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


}
