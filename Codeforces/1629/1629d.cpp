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
		set<string> arr;
		vector<string> v;

		string ans = "NO\n";

		for(int i=0; i<n; i++){
			string s;
			cin >> s;
			string rev = s;
			reverse(rev.begin(), rev.end());

			if(s == rev || arr.find(rev) != arr.end())
				ans = "YES\n";
			

			v.push_back(s);
			arr.insert(s);
		}

		if(ans == "YES\n"){
			cout << ans;
			continue;
		}

		int freq1[26][26] = {0}, freq2[26][26] = {0};

		for(int i=n-1; i>=0; i--){
			if(v[i].size() == 2)
				freq1[v[i][0]-'a'][v[i][1]-'a']++;
			else
				freq2[v[i][1]-'a'][v[i][2]-'a']++;
		}

		for(int i=0; i<n; i++){
			if(v[i].size() == 2){
				freq1[v[i][0]-'a'][v[i][1]-'a']--;
				if(freq2[v[i][1]-'a'][v[i][0]-'a'] > 0)
					ans = "YES\n";
			}
			else{
				freq2[v[i][1]-'a'][v[i][2]-'a']--;
				if(freq1[v[i][1]-'a'][v[i][0]-'a'] > 0)
					ans = "YES\n";
			}
		}

		cout << ans;

	}
}
