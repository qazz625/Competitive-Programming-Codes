#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

string alphabets = "abcdefghijklmnopqrstuvwxyz";
int n, k;

int solve(vector<int> freq, int c, int ind){
	// debug("AA");
	freq[c]++;
	int rem = n-ind-1;

	for(int i=0; i<26; i++){
		int to_add = (k-freq[i]%k)%k;
		rem -= to_add;
	}

	if(rem >= 0 && rem%k == 0)
		return ind;
	else
		return -1;
}

string find(vector<int> garr, int c, int ind){
	garr[c]++;
	string s;
	int rem = n-ind-1;
	for(int i=0; i<26; i++){
		int to_add = (k-garr[i]%k)%k;
		for(int j=0; j<to_add; j++)
			s += alphabets[i];
		rem -= to_add;
	}
	if(rem < 0 || rem%k != 0){
		return "~";
	}

	string s2;
	for(int i=0; i<rem; i++)
		s2 += 'a';
	return s2+s;
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		string s;
		cin >> s;
		if(n%k != 0){
			cout << "-1\n";
			continue;
		}

		vector<int> pref[n];
		vector<int> cur(26);

		for(int i=0; i<n; i++){
			cur[s[i]-'a']++;
			pref[i] = cur;
		}

		int flag = 0;
		for(int i=0; i<26; i++){
			if(pref[n-1][i]%k != 0)
				flag = 1;
		}

		if(flag == 0){
			cout << s << "\n";
			continue;
		}

		int ans = -1;
		vector<int> temp(26);
		for(int i=s[0]-'a'+1; i<26; i++){
			int x = solve(temp, i, 0);
			if(x != -1)
				ans = x;
		}

		for(int i=1; i<n; i++){
			for(int j=s[i]-'a'+1; j<26; j++){
				int x = solve(pref[i-1], j, i);
				if(x != -1)
					ans = x;
			}
		}

		vector<int> garr;
		if(ans == 0)
			garr = temp;
		else
			garr = pref[ans-1];
		

		string res;
		for(int i=0; i<n; i++)
			res += 'z';

		for(int i=s[ans]-'a'+1; i<26; i++){
			string as = find(garr, i, ans);
			string s2;
			for(int j=0; j<ans; j++)
				s2 += s[j];
			if(as != "~")
				res = min(res, s2+alphabets[i]+as);
		}

		cout << res << "\n";
	}
}
