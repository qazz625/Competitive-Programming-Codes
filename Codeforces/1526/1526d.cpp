#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag,
 tree_order_statistics_node_update> 
    pbds_set; 
    
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int findInversion(vector<int> &arr){
	int invcount = 0;
	pbds_set s;
	for(int i=arr.size()-1; i>=0; i--){
		invcount += s.order_of_key(arr[i]);
		s.insert(arr[i]);
	}
	return invcount;
}

int solve(vector<char> &characters, map<char, int> &freqs, string &s){
	int num = 0;
	vector<int> arr(s.size());
	for(auto x: characters){
		for(int i=0; i<s.size(); i++){
			if(s[i] == x){
				arr[i] = num;
				num++;
			}
		}
	}
	int a = findInversion(arr);
	return a;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();

		map<char, int> freqs;
		vector<char> characters;

		for(int i=0; i<n; i++){
			freqs[s[i]]++;
			if(find(characters.begin(), characters.end(), s[i]) == characters.end())
				characters.push_back(s[i]);
		}

		// print(characters);
		// print(freqs);

		sort(characters.begin(), characters.end());

		int maxinv = -1;
		vector<char> ans;
		do{
			int curinv = solve(characters, freqs, s);
			if(curinv > maxinv){
				maxinv = curinv;
				ans = characters;
			}
		} while(next_permutation(characters.begin(), characters.end()));

		// debug("AA");
		// print(ans);

		for(auto x: ans){
			for(int i=0; i<freqs[x]; i++){
				cout << x;
			}
		}
		cout << "\n";

	}
}
