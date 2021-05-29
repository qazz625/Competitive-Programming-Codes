#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

void solve(vector<int> tree[], int v, int p, vector<pair<int, int>> &ans, vector<pair<int, int>> &arr){
	int left = 0, right = 0;
	for(auto x: tree[v]){
		if(x != p){
			solve(tree, x, v, ans, arr);
			int left1 = abs(arr[x].first-arr[v].first) + ans[x].first;
			int left2 = abs(arr[x].second-arr[v].first) + ans[x].second;
			left += max(left1, left2);

			int right1 = abs(arr[x].first-arr[v].second) + ans[x].first;
			int right2 = abs(arr[x].second-arr[v].second) + ans[x].second;
			right += max(right1, right2);
		}
	}

	ans[v].first = left;
	ans[v].second = right;

}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int, int>> arr(n);
		for(int i=0; i<n; i++){
			cin >> arr[i].first >> arr[i].second;
		}

		vector<int> tree[n];
		for(int i=0; i<n-1; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		vector<pair<int, int>> ans(n);
		solve(tree, 0, -1, ans, arr);
		cout << max(ans[0].first, ans[0].second) << "\n";
	}
}

