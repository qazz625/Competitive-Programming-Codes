#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int check(string &s, int start, int end, vector<vector<int>> &evenpref, vector<vector<int>> &oddpref){
	vector<int> even = evenpref[end], odd = oddpref[end];
	// debug(start, end);
	if(start != 0){
		even[0] -= evenpref[start-1][0];
		even[1] -= evenpref[start-1][1];
		odd[0] -= oddpref[start-1][0];
		odd[1] -= oddpref[start-1][1];
	}

	bool c1 = even[0] == 0 && odd[1] == 0;
	bool c2 = even[1] == 0 && odd[0] == 0;
	if(c1 || c2)
		return 1;

	else
		return 0;

}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();

		if(n == 1){
			cout << "1\n";
			continue;
		}

		vector<vector<int>> evenpref(n, vector<int>(2, 0));
		vector<vector<int>> oddpref(n, vector<int>(2, 0));

		// debug("XX");


		if(s[0] != '?')
			evenpref[0][s[0]-'0']++;

		for(int i=1; i<n; i++){
			evenpref[i] = evenpref[i-1];
			oddpref[i] = oddpref[i-1];
			if(s[i] == '?')
				continue;
			if(i%2 == 0){
				evenpref[i][s[i]-'0']++;
			}
			else{
				oddpref[i][s[i]-'0']++;
			}
		}

		// print(evenpref);
		// print(oddpref);

		int tot = 0;
		// debug(tot);
		for(int i=0; i<n; i++){
			// debug(i);
			int st = i, e = n-1, ans = -1;
			while(st <= e){
				int mid = (st+e)/2;
				int poss = check(s, i, mid, evenpref, oddpref);
				// debug("BB");
				if(poss){
					ans = mid;
					st = mid+1;
				}
				else{
					e = mid-1;
				}
			}
			// debug(ans);
			// assert(ans != -1);
			tot += ans-i+1;
		}
		// debug("DD");
		cout << tot << endl;
		// debug("XX");
		// debug(t);
	}


}
