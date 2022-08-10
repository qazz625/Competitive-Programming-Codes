#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

string alphabets = "abcdefghijklmnopqrstuvwxyz";

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<string> arr(n);
		for(int i=0; i<n; i++)
			cin >> arr[i];

		vector<string> arr2(n-1);
		for(int i=0; i<n-1; i++)
			cin >> arr2[i];

		string ans;
		for(int i=0; i<m; i++){
			int alph1[26] = {0};
			int alph2[26] = {0};

			for(int j=0; j<n; j++)
				alph1[arr[j][i]-'a']++;
			for(int j=0; j<n-1; j++)
				alph2[arr2[j][i]-'a']++;

			for(int i=0; i<26; i++){
				if(alph1[i] - alph2[i] == 1)
					ans += alphabets[i];
			}
		}
		cout << ans << endl;
	}
}
