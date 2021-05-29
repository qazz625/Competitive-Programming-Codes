#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

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

	int freq[n+2] = {0};
	vector<int> ans(q);

	int prev = -1;
	int ptr1, ptr2;
	int maxfreqs[n+2];
	int maxfreqptr;
	for(int i=0; i<q; i++){
		if(queries[i][0] != prev){
			ptr1 = queries[i][0]*block_size, ptr2 = ptr1-1;
			prev = queries[i][0];
			for(int i=0; i<=n; i++){
				freq[i] = 0;
				maxfreqs[i] = 0;
			}
			maxfreqs[0] = n;
			maxfreqptr = 0;
		}
		int l = queries[i][2], r = queries[i][1];

		int lim = (r-l+1)/2;
		if((r-l+1)%2 == 1){
			lim++;
		}

		while(ptr2 != r){
			ptr2++;
			maxfreqs[freq[arr[ptr2]]]--;
			freq[arr[ptr2]]++;
			maxfreqs[freq[arr[ptr2]]]++;
			maxfreqptr= max(maxfreqptr, freq[arr[ptr2]]);
			
		}


		if(ptr1 > l){
			while(ptr1 != l){
				ptr1--;
				maxfreqs[freq[arr[ptr1]]]--;
				freq[arr[ptr1]]++;
				maxfreqs[freq[arr[ptr1]]]++;
				maxfreqptr= max(maxfreqptr, freq[arr[ptr1]]);
			}
		}
		else{
			while(ptr1 != l){
				// debug("DD");
				int temp = freq[arr[ptr1]];
				maxfreqs[temp]--;
				freq[arr[ptr1]]--;
				maxfreqs[freq[arr[ptr1]]]++;
				if(maxfreqs[temp] == 0 && maxfreqptr == temp)
					maxfreqptr--;
				ptr1++;
			}
		}

		
		if(maxfreqptr <= lim){
			ans[queries[i][3]] = 1;
		}
		else{
			int rem = (r-l+1) - maxfreqptr;
			int a = maxfreqptr - (rem+1);
			ans[queries[i][3]] = a+1;
		}

	}

	for(auto x: ans){
		cout << x << "\n";
	}
}
