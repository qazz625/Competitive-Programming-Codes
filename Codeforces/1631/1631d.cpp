#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n, k;
pair<int, int> check(vector<int> &arr, int val){
	int ptr1 = 0, ptr2 = -1;
	pair<int, int> ans = {-1, -1};
	while(ptr2+1 != n){
		if(arr[ptr2+1] - arr[ptr1] <= val){
			ptr2++;
		}
		else{
			ans = max(ans, {ptr2-ptr1+1, arr[ptr1]});
			ptr1++;
		}
	}
	ans = max(ans, {ptr2-ptr1+1, arr[ptr1]});
	return ans;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		vector<int> arr(n);
		for(int i=0; i<n; i++)
			cin >> arr[i];

		vector<int> oriarr = arr;
		sort(arr.begin(), arr.end());

		int s = 0, e = 100;
		pair<int, int> ans = {-1, -1};
		while(s <= e){
			int mid = (s+e)/2;
			pair<int, int> c = check(arr, mid);
			if(c.first != -1 && c.first - (n-c.first) >= k){
				ans = {c.second, c.second+mid};
				e = mid-1;
			}
			else{
				s = mid+1;
			}
		}
		print(ans);

		arr = oriarr;

		vector<pair<int, int>> partition;
		int prev = -1, cur = 0;
		for(int i=0; i<n; i++){
			debug(cur);
			if(arr[i] < ans.first || arr[i] > ans.second){
				cur--;
			}
			else{
				cur++;
			}
			if(cur > 0){
				debug(i);
				partition.push_back({prev+1, i});
				cur = 0;
				prev = i;
			}
		}

		print(partition);

		int combine = partition.size()-k;
		debug(combine);
		int r = partition.back().second;
		for(int i=0; i<combine; i++){
			partition.pop_back();
		}
		partition[partition.size()-1].second = r;

		cout << ans.first << " " << ans.second << "\n";
		for(auto x: partition){
			cout << x.first+1 << " " << x.second+1 << "\n";
		}
	}


}

//Read the stuff at the top