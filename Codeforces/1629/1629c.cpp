#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int freq[200010];
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		int suffmex[n] = {0};

		int ptr = -1;
		for(int i=n-1; i>=0; i--){
			freq[arr[i]]++;
			if(ptr == -1)
				ptr++;
			while(freq[ptr] > 0)
				ptr++;
			suffmex[i] = ptr;
		}

		for(int i=0; i<n; i++)
			freq[arr[i]]--;


		int ind = 0;
		vector<int> ans;
		while(ind != n){
			int goal = suffmex[ind], start = ind;
			ptr = -1;
			while(ind != n && ptr != goal){
				freq[arr[ind]]++;
				if(ptr == -1)
					ptr++;
				while(freq[ptr] > 0)
					ptr++;
				ind++;
			}

			for(int i=start; i<ind; i++)
				freq[arr[i]]--;

			ans.push_back(goal);
		}

		cout << ans.size() << "\n";
		for(auto x: ans){
			cout << x << " ";
		}
		cout << "\n";
	}	
}

