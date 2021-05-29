#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int a = 1'000;


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<int, int> mp;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			mp[x]++;
		}
		// print(mp);

		vector<int> v;
		for(auto x: mp)
			v.push_back(x.second);

		sort(v.begin(), v.end());

		if(v.size() == 1){
			cout << "0\n";
			continue;
		}

		vector<int> pref(v.size()), suff(v.size());
		pref[0] = v[0];
		for(int i=1; i<v.size(); i++)
			pref[i] = pref[i-1] + v[i];

		suff[v.size()-1] = v[v.size()-1];
		for(int i=v.size()-2; i>=0; i--)
			suff[i] = suff[i+1] + v[i];

		// print(v);
		// print(pref);
		// print(suff);

		int ans = 99999999;
		for(int i=1; i<v.size()-1; i++){
			int front = pref[i-1];
			int back = suff[i+1] - (v.size()-i-1)*v[i];
			ans = min(ans, front+back);
		}

		ans = min(ans, suff[1] - ((int)v.size()-1)*v[0]);
		ans = min(ans, pref[v.size()-2]);

		cout << ans << "\n";

	}
}