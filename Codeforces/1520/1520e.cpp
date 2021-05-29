#include <bits/stdc++.h>
using namespace std;

#define int long long

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

		vector<int> v;
		for(int i=0; i<n; i++){
			if(s[i] == '*')
				v.push_back(i);
		}
		int totstar = v.size();

		if(v.size() == 0){
			cout << "0\n";
			continue;
		}

		vector<int> center;

		if(totstar%2 == 0){
			center.push_back(v[v.size()/2]);
			center.push_back(v[v.size()/2 -1]);
		}
		else{
			center.push_back(v[v.size()/2]);
		}

		int ans = 1ll<<60;
		for(auto c: center){
			int curans = 0;
			int loc = c+1;
			for(int i=c+1; i<n; i++){
				if(s[i] == '*'){
					curans += i-loc;
					loc++;
				}
			}

			loc = c-1;
			for(int i=c-1; i>=0; i--){
				if(s[i] == '*'){
					curans += loc-i;
					loc -= 1;
				}
			}
			ans = min(ans, curans);
		}
		cout << ans << "\n";
	}
}
