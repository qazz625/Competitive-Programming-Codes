#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


pair<int, int> calcpref(vector<pair<int, int>> &pref, int l, int r){
	if(l == 0)
		return pref[r];
	else
		return {pref[r].first-pref[l-1].first, pref[r].second-pref[l-1].second};
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;

		vector<pair<int, int>> pref(n);
		if(s[0] == 'D')
			pref[0].first++;
		else
			pref[0].second++;

		for(int i=1; i<n; i++){
			pref[i] = pref[i-1];
			if(s[i] == 'D')
				pref[i].first++;
			else
				pref[i].second++;
		}

		// print(pref);

		vector<int> ans(n);
		for(int i=0; i<n; i++){
			pair<int, int> eq = calcpref(pref, 0, i);
			int left = 0, right = i;
			int parts = 1;
			while(right < n){
				pair<int, int> cur = calcpref(pref, left, right);
				// debug(left, right);
				if(cur.first*eq.second == cur.second*eq.first){
					ans[right] = max(ans[right], parts);
					parts++;
					left = right+1;
				}
				right++;
			}
			// print(ans);
		}

		for(auto x: ans){
			cout << x << " ";
		}
		cout << "\n";
	}


}
