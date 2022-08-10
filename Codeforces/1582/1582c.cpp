#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;

		vector<int> locations[26];
		for(int i=0; i<n; i++){
			locations[s[i]-'a'].push_back(i);
		}

		vector<int> prefsum[n];
		vector<int> cur(26, 0);
		for(int i=0; i<n; i++){
			cur[s[i]-'a']++;
			prefsum[i] = cur;
		}

		vector<int> suffsum[n];
		vector<int> cur2(26, 0);
		for(int i=n-1; i>=0; i--){
			cur2[s[i]-'a']++;
			suffsum[i] = cur2;
		}

		int flag = 0, ans = -1;
		for(int i=0; i<26; i++){
			string cur;
			int res = 0;
			for(int j=0; j<n; j++){
				if(i != s[j]-'a'){
					cur += s[j];
					res++;
				}
				else
					cur += '~';
			}
			// debug(i, cur);

			int ind1 = 0, ind2 = n-1;
			int count1 = 0, count2 = 0;
			while(ind1 != n && cur[ind1] == '~'){
				ind1++;
				count1++;
			}
			while(ind2 != -1 && cur[ind2] == '~'){
				ind2--;
				count2++;
			}

			if(ind1 == n){
				flag = 1;
				ans = n;
				break;
			}

			res += 2*min(count1, count2);
			// debug(cur, res, ind1, ind2);

			while(ind1 < ind2){
				// debug(ind1, ind2);
				ind1++;
				count1 = 0;
				while(cur[ind1] == '~'){
					ind1++;
					count1++;
				}

				ind2--;
				count2 = 0;
				while(cur[ind2] == '~'){
					ind2--;
					count2++;
				}

				if(ind1 <= ind2)
					res += 2*min(count1, count2);
				else
					res += min(count1, count2);
			}

			string temp;
			for(auto x: cur)
				if(x != '~')
					temp += x;

			string revtemp = temp;
			reverse(revtemp.begin(), revtemp.end());

			// debug(temp, revtemp);

			if(temp == revtemp){
				ans = max(ans, res);
				flag = 1;
			}
		}

		if(flag == 0){
			cout << "-1\n";
		}
		else{
			cout << n-ans << "\n";
		}
	}


}
