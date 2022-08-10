#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

vector<vector<int>> cur(3, vector<int>(3, 0));

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	s = '~'+s;

	vector<vector<int>> pref[n+1];
	pref[0] = cur;
	for(int i=1; i<=n; i++){
		cur[i%3][s[i]-'a']++;
		pref[i] = cur;
	}

	while(m--){
		int l, r;
		cin >> l >> r;
		vector<vector<int>> mat = pref[r];

		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				mat[i][j] -= pref[l-1][i][j];

		vector<int> v = {0, 1, 2};

		// print(mat);

		int ans = 1000000;
		do{
			int temp = 0;
			for(int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					if(j != v[i])
						temp += mat[i][j];
				}
			}
			ans = min(ans, temp);
		}
		while(next_permutation(v.begin(), v.end()));

		cout << ans << "\n";
	}
}

