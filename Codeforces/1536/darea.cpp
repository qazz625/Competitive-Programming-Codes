#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n;
int inf = 1e18+20;

int solve(vector<pair<int, int>> &vp){
	vector<int> prefmax(n), suffmax(n);
	vector<int> prefmin(n), suffmin(n);

	prefmax[0] = vp[0].second;
	prefmin[0] = vp[0].second;
	for(int i=1; i<n; i++){
		prefmax[i] = max(prefmax[i-1], vp[i].second);
		prefmin[i] = min(prefmin[i-1], vp[i].second);
	}

	suffmax[n-1] = vp[n-1].second;
	suffmin[n-1] = vp[n-1].second;
	for(int i=n-2; i>=0; i--){
		suffmax[i] = max(suffmax[i+1], vp[i].second);
		suffmin[i] = min(suffmin[i+1], vp[i].second);
	}

	int ans = inf;
	for(int i=0; i<n-1; i++){
		int rect1l = prefmax[i]-prefmin[i];
		int rect1b = vp[i].first-vp[0].first;
		int rect2l = suffmax[i+1]-suffmin[i+1];
		int rect2b = vp[n-1].first-vp[i+1].first;

		ans = min(ans, rect1l*rect1b + rect2l*rect2b);
	}
	return ans;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		vector<pair<int, int>> vp(n);

		for(int i=0; i<n; i++){
			cin >> vp[i].first >> vp[i].second;
		}

		if(n <= 2){
			cout << "0\n";
			continue;
		}

		sort(vp.begin(), vp.end());
		int ans1 = solve(vp);

		for(int i=0; i<n; i++)
			swap(vp[i].first, vp[i].second);
		sort(vp.begin(), vp.end());
		int ans2 = solve(vp);

		cout << min(ans1, ans2) << "\n";
	}
}
