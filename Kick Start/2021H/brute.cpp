#include <bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE
// 	#define _GLIBCXX_DEBUG
// 	#include "../../../debug.cpp"
// #endif

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

		int flag = 1;
		while(flag == 1){

			flag = 0;
			for(int i=1; i<=9; i++){
				int ind = 0;
				string news;
				while(ind != s.size()){
					if(ind+1 == s.size()){
						news += s[ind];
						ind++;
					}
					else if(s[ind+1]-'0' == i && s[ind]-'0' == i-1){
						flag = 1;
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
					flag = 1;
					news += '1';
					ind += 2;
				}
				else{
					news += s[ind];
					ind++;
				}
			}

			// debug(s, news);
			s = news;
		}

		// cout << "Case #" << tt+1 << ": ";
		cout << s << "\n";
	}
}

