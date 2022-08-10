#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

vector<vector<int>> pref(500010, vector<int>(26, 0));
vector<vector<int>> suff(500010, vector<int>(26, 0));

string alphabets = "abcdefghijklmnopqrstuvwxyz";
string check(string goal, string s){
	// debug(goal, s);
	int done[26] = {0};
	string cur;
	string order;
	while(cur.size() < goal.size()){
		cur += s;
		char remove = -1;
		for(int i=0; i<26; i++){
			// debug(i, cur.size());
			if(suff[cur.size()][i] == 0 && pref[cur.size()-1][i] != 0 && done[i] == 0){
				remove = i;
				done[remove] = 1;
				order += alphabets[i];
			}
		}

		if(remove == -1)
			return "";

		string temp;
		for(int i=0; i<s.size(); i++){
			if(s[i]-'a' != remove)
				temp += s[i];
		}
		s = temp;
	}
	// debug(goal, s);

	if(cur == goal && s.size() == 0)
		return order;
	else
		return "";
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();

		vector<int> alph(26);
		pref[n] = alph;
		pref[n+1] = alph;
		for(int i=0; i<n; i++){
			alph[s[i]-'a']++;
			pref[i] = alph;
		}

		vector<int> alph2(26);
		suff[n] = alph2;
		suff[n+1] = alph2;
		for(int i=n-1; i>=0; i--){
			alph2[s[i]-'a']++;
			suff[i] = alph2;
		}

		string cur;
		string res = "~";
		string order;
		for(int i=0; i<n; i++){
			cur += s[i];
			string temp = check(s, cur);
			if(temp.size() != 0){
				res = cur;
				order = temp;
				break;
			}
		}

		if(res == "~")
			cout << "-1\n";
		else
			cout << res << " " << order << "\n";

	}


}

//Read the stuff at the top