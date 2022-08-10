#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

struct stacked{
	int l, r;
	int val;
	stacked(int l, int r, int val){
		this->l = l;
		this->r = r;
		this->val = val;
	}
};

bool comp(stacked &s1, stacked &s2){
	return s1.val > s2.val;
}

int32_t main(){
	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++){
		int n, c;
		cin >> n >> c;
		map<int, pair<int, int>> mp;
		for(int i=0; i<n; i++){
			int l, r;
			cin >> l >> r;
			mp[l].first++;
			mp[r].second++;
		}

		int prev = 0;
		int cur = 0;
		vector<stacked> v;
		for(auto x: mp){
			if(prev <= x.first-1 && prev != 0){
				stacked st1(prev, x.first-1, cur);
				v.push_back(st1);
			}

			cur -= x.second.second;
			stacked st2(x.first, x.first, cur);
			v.push_back(st2);
			cur += x.second.first;
			prev = x.first+1;
		}

		sort(v.begin(), v.end(), comp);

		// for(auto x: v){
		// 	cout << x.l << " " << x.r << " " << x.val << "\n";
		// }

		int ans = n;
		for(int i=0; i<v.size(); i++){
			if(v[i].r - v[i].l + 1 <= c ){
				c -= v[i].r - v[i].l + 1;
				ans += (v[i].r - v[i].l + 1)*v[i].val;
			}
			else{
				ans += c*v[i].val;
				break;
			}
		}
		cout << "Case #" << tt+1 << ": ";
		cout << ans << "\n";
	}
}

