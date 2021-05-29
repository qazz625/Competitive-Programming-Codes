#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	vector<vector<int>> queries;
	int block_size = sqrt(n);
	for(int i=0; i<q; i++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		int blocknum = l/block_size;
		queries.push_back({blocknum, r, l, i});
	}

	sort(queries.begin(), queries.end());
	// print(queries);

	int freq[n+2] = {0};
	set<pair<int, int>> s;
	vector<int> ans(q);

	int prev = -1;
	int ptr1, ptr2;
	int curmax;
	for(int i=0; i<q; i++){
		if(queries[i][0] != prev){
			ptr1 = queries[i][0]*block_size, ptr2 = ptr1-1;
			prev = queries[i][0];
			for(auto x: s){
				freq[x.second] = 0;
			}
			curmax = 0;
			s.clear();
		}
		int l = queries[i][2], r = queries[i][1];
		// debug(l, r);
		// print(s);
		// print(freq, n+1);
		// debug(ptr1, ptr2);

		while(ptr2 != r){
			ptr2++;
			s.erase({freq[arr[ptr2]], arr[ptr2]});
			freq[arr[ptr2]]++;
			s.insert({freq[arr[ptr2]], arr[ptr2]});
		}

		if(ptr1 > l){
			while(ptr1 != l){
				ptr1--;
				s.erase({freq[arr[ptr1]], arr[ptr1]});
				freq[arr[ptr1]]++;
				s.insert({freq[arr[ptr1]], arr[ptr1]});
			}
		}
		else{
			while(ptr1 != l){
				s.erase({freq[arr[ptr1]], arr[ptr1]});
				freq[arr[ptr1]]--;
				s.insert({freq[arr[ptr1]], arr[ptr1]});
				ptr1++;
			}
		}

		auto ptr = s.end();
		ptr--;

		int lim = (r-l+1)/2;
		if((r-l+1)%2 == 1){
			lim++;
		}
		if(ptr->first <= lim){
			ans[queries[i][3]] = 1;
		}
		else{
			int rem = (r-l+1) - ptr->first;
			int a = ptr->first - (rem+1);
			ans[queries[i][3]] = a+1;
		}

	}

	for(auto x: ans){
		cout << x << "\n";
	}
}
