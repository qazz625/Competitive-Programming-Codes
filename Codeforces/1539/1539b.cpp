#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

vector<int> find(vector<vector<int>> &prefix, int l, int r){
	if(l == 0)
		return prefix[r];
	else{
		vector<int> ret(26, 0);
		for(int i=0; i<26; i++)
			ret[i] = prefix[r][i] - prefix[l-1][i];
		return ret;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	vector<vector<int>> prefix(n);
	vector<int> cur(26, 0);

	for(int i=0; i<n; i++){
		cur[s[i]-'a']++;
		prefix[i] = cur;
	}

	while(q--){
		int l, r;
		cin >> l >> r;
		l--; r--;
		vector<int> freq = find(prefix, l, r);
		int ans = 0;
		for(int i=0; i<26; i++){
			ans += (i+1)*freq[i];
		}
		cout << ans << "\n";
	}
}

