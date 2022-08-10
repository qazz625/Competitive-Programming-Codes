#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int solve(vector<pair<int, int>> &arr, int val){
	// debug(val);
	pair<int, int> cur = {val-1, 0};
	int count = 0;
	for(int i=0; i<arr.size(); i++){
		// print(cur);
		if(arr[i].first >= cur.first && arr[i].second >= cur.second){
			cur.first--;
			cur.second++;
			count++;
		}
		if(count == val){
			return 1;
		}
	}
	return 0;
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

		int s = 1, e = n, ans = -1;
		while(s <= e){
			int mid = (s+e)/2;
			int c = solve(arr, mid);
			if(c == 1){
				ans = mid;
				s = mid+1;
			}
			else{
				e = mid-1;
			}
		}

		cout << ans << "\n";
	}


}

//Read the stuff at the top