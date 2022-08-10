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
		int n;
		cin >> n;
		int a[n], asort[n], b[n], bsort[n];
		for(int i=0; i<n; i++){
			cin >> a[i];
			asort[i] = a[i];
		}
		for(int i=0; i<n; i++){
			cin >> b[i];
			bsort[i] = b[i];
		}

		sort(asort, asort+n);
		sort(bsort, bsort+n);

		vector<pair<int, int>> ans;
		for(int i=0; i<n; i++){
			for(int j=0; j<n-1; j++){
				if(a[j] > a[j+1] || (a[j] == a[j+1] && b[j] > b[j+1])){
					swap(a[j], a[j+1]);
					swap(b[j], b[j+1]);
					ans.push_back({j, j+1});
				}
			}
		}

		// print(a, n);
		// print(b, n);

		int l = ans.size();
		for(int i=0; i<n; i++){
			if(b[i] != bsort[i])
				l = -1;
		}

		cout << l << "\n";

		if(l != -1){
			for(auto x: ans){
				cout << x.first+1 << " " << x.second+1 << "\n";
			}
		}
		
	}


}
