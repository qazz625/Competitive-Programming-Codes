#include <bits/stdc++.h>
using namespace std;

void update(vector<pair<int, int>> &segtree, int l, int r, int x, int y, int ind, int val){
	if(r < x || l > y)
		return;
	else if(x >= l && y <= r){
		segtree[ind].second = val;
		segtree[ind].first = (y-x+1)*val;
	}
	else{
		int mid = (x+y)/2;
		if(segtree[ind].second != -1){
			segtree[2*ind].second = segtree[ind].second;
			segtree[2*ind+1].second = segtree[ind].second;
			segtree[ind].second = -1;
		}
		update(segtree, l, r, x, mid, 2*ind, val);
		update(segtree, l, r, mid+1, y, 2*ind+1, val);
		segtree[ind].first = segtree[2*ind].first + segtree[2*ind+1].first;
	}
}

int query(vector<pair<int, int>> &segtree, int l, int r, int x, int y, int ind){
	if(r < x || l > y){
		if(segtree[ind].second != -1)
			segtree[ind].first = segtree[ind].second*(y-x+1);
		return 0;
	}
	else if(x >= l && y <= r){
		if(segtree[ind].second != -1)
			segtree[ind].first = segtree[ind].second*(y-x+1);
		return segtree[ind].first;
	}
	else{
		int mid = (x+y)/2;
		if(segtree[ind].second != -1){
			segtree[2*ind].second = segtree[ind].second;
			segtree[2*ind+1].second = segtree[ind].second;
			segtree[ind].second = -1;
		}
		int a = query(segtree, l, r, x, mid, 2*ind);
		int b = query(segtree, l, r, mid+1, y, 2*ind+1);
		segtree[ind].first = segtree[2*ind].first + segtree[2*ind+1].first;
		return a+b;
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		string s, f;
		cin >> s >> f;

		vector<int> v(n);
		for(int i=0; i<n; i++)
			v[i] = f[i]-'0';

		while((1<<30)%v.size() != 0)
			v.push_back(0);

		vector<pair<int, int>> segtree(2*v.size());
		for(int i=0; i<v.size(); i++){
			segtree[i+v.size()].first = v[i];
			segtree[i+v.size()].second = -1;
		}

		for(int i=segtree.size()-1; i!=1; i-=2){
			segtree[i/2].first = segtree[i].first + segtree[i-1].first;
			segtree[i/2].second = -1;
		}

		vector<pair<int, int>> queries;
		for(int i=0; i<q; i++){
			int l, r;
			cin >> l >> r;
			l--; r--;
			queries.push_back({l, r});
		}

		reverse(queries.begin(), queries.end());


		int flag = 0;
		for(auto p: queries){
			int l = p.first, r = p.second;
			int one = query(segtree, l, r, 0, v.size()-1, 1);
			int zero = (r-l+1)-one;
			if(one == zero){
				flag = 1;
				break;
			}

			if(one > zero)
				update(segtree, l, r, 0, v.size()-1, 1, 1);
			else
				update(segtree, l, r, 0, v.size()-1, 1, 0);
		}

		for(int i=0; i<n; i++){
			int num = query(segtree, i, i, 0, v.size()-1, 1);
			if(num != s[i]-'0'){
				flag = 1;
			}
		}

		if(flag == 1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
}
