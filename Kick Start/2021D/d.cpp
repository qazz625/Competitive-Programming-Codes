#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 5

vector<pair<int, int>> arr;
vector<pair<int, int>> segTrees;

vector<pair<int, int>> buildSegTree(vector<pair<int, int>> &arr){
	while((1<<30)%arr.size() != 0)
		arr.push_back({0, 0});
	vector<pair<int, int>> segtree(2*arr.size());
	for(int i=0; i<arr.size(); i++){
		segtree[i+arr.size()] = arr[i]; 
	}
	for(int i=segtree.size()-1; i != 1; i-=2){
		segtree[i/2].first = segtree[i].first + segtree[i-1].first;
		segtree[i/2].second = segtree[i].second + segtree[i-1].second;
	}
	return segtree;
}

void update(vector<pair<int, int>> &segtree, int pos, pair<int, int> val){
	pos += segtree.size()/2;
	while(pos != 0){
		segtree[pos].first += val.first;
		segtree[pos].second += val.second;
		pos /= 2;
	}
}

pair<int, int> query(vector<pair<int, int>> &segtree, int x, int y, int l, int r, int ind){
	if(l > y || x > r){
		return {0, 0};
	}
	else if(x >= l && y <= r){
		return segtree[ind];
	}
	else{
		int mid = (x+y)/2;
		pair<int, int> a = query(segtree, x, mid, l, r, 2*ind);
		pair<int, int> b = query(segtree, mid+1, y, l, r, 2*ind+1);
		return {a.first + b.first, a.second + b.second};
	}
}


int fun(int a, int p){
	if(a == 0)
		return 0;
	int count = 0;
	while(a%p == 0){
		count++;
		a /= p;
	}
	return count;
}

int32_t main(){
	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++){
		int n, q, p;
		cin >> n >> q >> p;
		arr.resize(n);

		for(int i=0; i<n; i++){
			int num;
			cin >> num;
			if(num%p == 0){
				arr[i] = {1, fun(fun(num, p), p)};
			}
			else{
				arr[i] = {0, 0};
			}
		}

		segTrees = buildSegTree(arr);
		cout << "Case #" << tt+1 << ": ";

		while(q--){
			int type;
			cin >> type;
			if(type == 1){
				int pos, val;
				cin >> pos >> val;
				pos--;

				update(segTrees, pos, make_pair(-arr[pos].first, -arr[pos].second));
				if(val%p == 0){
					arr[pos] = {1, fun(fun(val, p), p)};
				}
				else{
					arr[pos] = {0, 0};
				}
				update(segTrees, pos, arr[pos]);
			}
			else{
				int s, l, r;
				cin >> s >> l >> r;
				l--; r--;
				pair<int, int> ans = query(segTrees, 0, segTrees.size()/2-1, l, r, 1);
				cout << ans.first*fun(s, p) + ans.second << " ";
			}
		}
		cout << "\n";
	}
}
