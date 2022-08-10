/*
THINGS TO DO
1) Check integer overflows
2) Check corner cases
3) Compile and run once on terminal
4) Code smart, not quick
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

typedef tree<int, null_type, less<int>, rb_tree_tag,
 tree_order_statistics_node_update> 
    pbds_set; 
    
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
   
#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int in[400000], out[400000];
int curtime = 0;

void dfs(vector<int> tree[], vector<int> &euler, int p, int v){
	euler.push_back(v);
	in[v] = curtime;
	curtime++;
	for(auto x: tree[v]){
		if(x != p){
			dfs(tree, euler, v, x);
		}
	}
	euler.push_back(v);
	out[v] = curtime;
	curtime++;
}

int query(vector<int> &segtree, int l, int r, int x, int y, int ind){
	if(r < x || l > y){
		return 0;
	}
	else if(x >= l && y <= r){
		return segtree[ind];
	}
	else{
		int mid = (x+y)/2;
		int a = query(segtree, l, r, x, mid, 2*ind);
		int b = query(segtree, l, r, mid+1, y, 2*ind+1);
		return a+b;
	}
}

void update(vector<int> &segtree, int ind, int val){
	ind += segtree.size()/2;
	while(ind != 0){
		segtree[ind] += val;
		ind /= 2;
	}
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){

		curtime = 0;

		int n;
		cin >> n;
		vector<int> tree[n];
		for(int i=1; i<n; i++){
			int x;
			cin >> x;
			x--;
			tree[x].push_back(i);
			tree[i].push_back(x);
		}

		vector<pair<int, int>> arr(n);
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			arr[i] = {x, i};
		}

		sort(arr.begin(), arr.end());
		vector<int> weights(n);
		for(int i=0; i<n; i++){
			arr[i].first = i;
			weights[arr[i].second] = arr[i].first;
		}

		vector<int> euler;
		dfs(tree, euler, -1, 0);

		print(weights);
		print(euler);
		print(in, n);
		print(out, n);

		while((1<<30)%euler.size() != 0)
			euler.push_back(-1);

		vector<int> segtree(2*euler.size());

		for(int i=n-1; i>=0; i--){
			int index = arr[i].second;
			int l = in[index], r = out[index];
			update(segtree, l, 1);
			update(segtree, r, 1);
			int ans;
			l++; r--;
			if(r < l)
				ans = 0;
			else
				ans = query(segtree, l, r, 0, euler.size()-1, 1);

			debug(ans/2);
			update(segtree, l, ans/2);
			update(segtree, r, ans/2);
			print(segtree);
		}

		int res = query(segtree, in[0], in[0], 0, euler.size()-1, 1);
		debug(res/2);


	}


}

//Read the stuff at the top