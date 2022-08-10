#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


void dfs(vector<int> tree[], int v, int p, int d, vector<int> &depths){
	depths[d]++;
	for(auto x: tree[v]){
		if(x != p){
			dfs(tree, x, v, d+1, depths);
		}
	}
}

int check(vector<int> &arr, int val){
	int flag = 1;
	int ind = 0;
	while(ind != arr.size() && arr[ind] != 0){
		int infected = 0;
		// debug(val);
		while (val != 0){
			if(infected != 0 && arr[ind] - infected <= val){
				break;
			}
			else{
				if(infected != 0)
					infected += 1; //spread
				infected += 1; // inject
				val -= 1;
			}
		}

		if(infected == 0 || arr[ind] - infected > val)
			flag = 0;
		ind++;
	}

	return flag;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		vector<int> tree[n];
		for(int i=1; i<n; i++){
			cin >> arr[i];
			arr[i]--;
			tree[arr[i]].push_back(i);
			tree[i].push_back(arr[i]);
		}

		// for(int i=0; i<n; i++){
		// 	print(tree[i]);
		// }

		vector<int> depths(n);

		dfs(tree, 0, -1, 0, depths);


		sort(depths.begin(), depths.end(), greater<int>());

		// print(depths);
		int s = 1, e = 1<<20, ans = -1;

		while(s <= e){
			int mid = (s+e)/2;
			int c = check(depths, mid);
			// debug(mid, c);
			if(c == 1){
				ans = mid;
				e = mid-1;
			}
			else{
				s = mid+1;
			}
		}

		cout << ans << "\n";
	}
}

