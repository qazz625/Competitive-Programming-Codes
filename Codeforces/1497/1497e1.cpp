#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int MAX = 10000010;

int pfact[10000010];

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int prime_number = 0;
	map<int, int> prime_mapper;
	for(int i=2; i<MAX; i++){
		if(pfact[i] != 0)
			continue;
		prime_mapper[i] = prime_number;
		prime_number++;
		for(int j=i; j<MAX; j+=i){
			pfact[j] = i;
		}
	}
	// print(pfact, 30);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		map<int, set<string>> mp;
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}

		int ind = 0, ans = 0;
		while(ind != n){
			int large_factor = 0;
			int num = arr[ind];
			bitset<600> bs;
			while(num != 1){
				if(pfact[num] >= 4000){
					large_factor = pfact[num];
				}
				else{
					int pos = prime_mapper[pfact[num]];
					bs[pos].flip();
				}
				num /= pfact[num];
			}

			string s;
			for(int i=0; i<600; i++){
				if(bs[i])
					s += '1';
				else
					s += '0';
			}
			// debug(arr[ind], large_factor, s);
			if(mp[large_factor].find(s) == mp[large_factor].end()){
				mp[large_factor].insert(s);
				ind++;
			}
			else{
				mp.clear();
				ans++;
			}
		}
		ans++;
		cout << ans << "\n";
	}
}

