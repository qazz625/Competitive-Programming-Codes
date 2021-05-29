#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int n;
	cin >> n;

	int inp[n];
	multiset<int> s;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		s.insert(x);
		inp[i] = x;
	}

	vector<int> res;
	int mintot = 1000000000000000;

	for(int i=0; i<n; i++){
		multiset<int> arr = s;
		vector<int> ans;
		int tot = 0;
		ans.push_back(inp[i]);
		arr.erase(arr.find(inp[i]));
		int curmax = inp[i], curmin = inp[i];

		for(int j=1; j<n; j++){
			// debug(j);
			// print(ans);
			// print(arr);
			auto ptr = arr.upper_bound(ans[j-1]);

			if(ptr == arr.begin()){
				ans.push_back(*ptr);
				arr.erase(arr.begin());
			}
			else if(ptr == arr.end()){
				ptr--;
				ans.push_back(*ptr);
				arr.erase(ptr);
			}
			else{
				auto ptr2 = ptr;
				ptr2--;
				if(ans[j-1]-(*ptr2) > (*ptr)-ans[j-1]){
					ans.push_back(*ptr);
					arr.erase(ptr);
				}
				else{
					ans.push_back(*ptr2);
					arr.erase(ptr2);
				}
			}

			curmax = max(curmax, ans.back());
			curmin = min(curmin, ans.back());
			tot += curmax-curmin;
		}

		debug(i, tot);

		if(tot < mintot){
			mintot = tot;
			res = ans;
		}
	}

	debug(mintot);


}

//Read the stuff at the top