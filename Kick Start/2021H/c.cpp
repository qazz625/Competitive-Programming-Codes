#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

string alphabets = "0123456789";
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++){
		int n;
		cin >> n;
		string s;
		cin >> s;


		for(int i=1; i<=9; i++){
			int ind = 0;
			string news;
			while(ind != s.size()){
				if(ind+1 == s.size()){
					news += s[ind];
					ind++;
				}
				else if(s[ind+1]-'0' == i && s[ind]-'0' == i-1){
					// debug(alphabets[(s[ind+1]-'0'+1)%10]);
					news += alphabets[(s[ind+1]-'0'+1)%10];
					ind += 2;
				}
				else{
					news += s[ind];
					ind++;
				}
			}
			// debug(s, news, i);
			s = news;
		}

		// debug(s);

		int ind = 0;
		string news;
		while(ind != s.size()){
			if(ind+1 == s.size()){
				news += s[ind];
				ind++;
			}
			else if(s[ind] == '9' && s[ind+1] == '0'){
				news += '1';
				ind += 2;
			}
			else{
				news += s[ind];
				ind++;
			}
		}

		debug(s, news);
		s = news;

		news = "";
		vector<char> v = {s[0]};
		for(int i=1; i<s.size(); i++){
			if(v.size() == 1){
				if((s[i] - v[0] + 10)%10 == 1){
					v.push_back(s[i]);
				}
				else{
					news += v[0];
					v = {s[i]};
				}
			}
			else{
				if((s[i] - v.back() + 10)%10 == 2){
					v.push_back(s[i]);
				}
				else{
					news += alphabets[v.back()+1];
					v = {s[i]};
				}
			}
		}

		if(v.size() == 1){
			news += v[0];
		}
		else{
			news += alphabets[v.back()+1];
		}

		// cout << "Case #" << tt+1 << ": ";
		cout << s << "\n";
	}
}

