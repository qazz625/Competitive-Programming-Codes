#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n;

string solve(string s1, string s2, int par){
	string ans;

	// debug(s1, s2, par);

	int ptr1 = 0, ptr2 = 0;
	while(ptr1 != 2*n || ptr2 != 2*n){
		if(ptr1 == 2*n){
			ans += s2[ptr2];
			ptr2++;
		}

		else if(ptr2 == 2*n){
			ans += s1[ptr1];
			ptr1++;
		}

		else{
					// debug(s1[ptr1], s2[ptr2]);

			if(s1[ptr1] == s2[ptr2]){
				ans += s1[ptr1];
				ptr1++;
				ptr2++;
			}
			else if(s1[ptr1]-'0' != par){
				ans += s1[ptr1];
				ptr1++;
			}
			else if(s2[ptr2]-'0' != par){
				ans += s2[ptr2];
				ptr2++;
			}
		}

		// debug(ptr1, ptr2, ans);

		// cout << "\n";

	}

	// debug(ptr2);

	for(; ptr2 != 2*n; ptr2++)
		ans += s2[ptr2];

	return ans;
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		cin >> n;
		string s1, s2, s3;

		cin >> s1 >> s2 >> s3;

		int z1 = count(s1.begin(), s1.end(), '0'), o1 = count(s1.begin(), s1.end(), '1');
		int z2 = count(s2.begin(), s2.end(), '0'), o2 = count(s2.begin(), s2.end(), '1');
		int z3 = count(s3.begin(), s3.end(), '0'), o3 = count(s3.begin(), s3.end(), '1');

		vector<int> zero, one;
		vector<string> arr = {s1, s2, s3};

		if(z1 >= o1)
			zero.push_back(1);
		else
			one.push_back(1);

		if(z2 >= o2)
			zero.push_back(2);
		else
			one.push_back(2);

		if(z3 >= o3)
			zero.push_back(3);
		else
			one.push_back(3);

		// print(zero);
		// print(one);

		string ans;
		if(zero.size() > one.size()){
			ans = solve(arr[zero[0]-1], arr[zero[1]-1], 0);
		}
		else{
			ans = solve(arr[one[0]-1], arr[one[1]-1], 1);
		}

		cout << ans << "\n";

		// assert(ans.size() <= 3*n);

	}
}
