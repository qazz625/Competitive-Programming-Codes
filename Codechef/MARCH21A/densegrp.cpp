#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

vector<vector<int>> check(set<vector<int>> &s, vector<pair<int, int>> &vp){
	sort(vp.begin(), vp.end());
	vector<vector<int>> ret;
	auto itr = s.begin();
	for(int i=0; i<vp.size(); i++){
		while(itr != s.end() && (*itr)[0] <= vp[i].second){
			if(!( (*itr)[1] < vp[i].first || (*itr)[0] > vp[i].second)){
				ret.push_back(*itr);
			}
			itr++;
		}
	}
	return ret;
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n, m, x, y;
		cin >> n >> m >> x>> y;
		set<vector<int>> sv;
		for(int i=0; i<m; i++){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			sv.insert({a, b, c, d});
		}

		vector<pair<int, int>> ans[m+10];
		ans[0].push_back({x, x});
		int cur = 0;
		while(sv.size() != 0){
			vector<vector<int>> remove = check(sv, ans[cur]);
			if(remove.size() == 0){
				break;
			}

			for(auto v: remove){
				ans[cur+1].push_back({v[2], v[3]});
				sv.erase(v);
			}
			cur++;
		}

		// for(int i=0; i<m; i++){
		// 	print(ans[i]);
		// }

		int res = -1;
		for(int i=m; i>=0; i--){
			for(auto p: ans[i]){
				if(p.first <= y && y <= p.second)
					res = i;
			}
		}

		cout << res << "\n";
	}
}
