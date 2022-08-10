#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0; i<n; i++)
			cin >> arr[i];

		int ans = 0;
		deque<int> dq;
		int ptr1 = 0, ptr2 = 0;
		map<int, int> mp;
		while(ptr2 != n){
			bool cond1 = mp[arr[ptr2]] == 0;
			bool cond2 = mp[arr[ptr2]] == 1 && dq.front() == arr[ptr2];
			if(cond1){
				dq.push_back(arr[ptr2]);
				mp[arr[ptr2]]++;
				ans += dq.size();
				ptr2++;
			}
			else if(cond2){
				dq.push_back(arr[ptr2]);
				mp[arr[ptr2]]++;
				ans += dq.size();
				ptr2++;
				mp[arr[ptr1]]--;
				dq.pop_front();
				ptr1++;
			}
			else{
				mp[arr[ptr1]]--;
				dq.pop_front();
				ptr1++;
			}
		}

		cout << ans << "\n";
	}	
}