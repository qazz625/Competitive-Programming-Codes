#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &segtree, int loc, string &s){
	int n = segtree.size();
	while(loc != n){
		int ind1 = n-2*(n-loc), ind2 = n-(2*(n-loc)+1);
		if(ind1 <= 0 || ind2 <= 0){
			if(s[loc-1] == '?')
				segtree[loc] = 2;
			else if(s[loc-1] == '0')
				segtree[loc] = 1;
			else
				segtree[loc] = 1;
			loc = n - (n-loc)/2;
			continue;
		}
		if(s[loc-1] == '?')
			segtree[loc] = segtree[ind1] + segtree[ind2];
		else if(s[loc-1] == '0')
			segtree[loc] = segtree[ind2];
		else
			segtree[loc] = segtree[ind1];

		loc = n - (n-loc)/2;
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;
	string s;
	cin >> s;
	vector<int> segtree(1<<k);
	int n = (1<<k);

	for(int i=1; i<(1<<k); i++){
		update(segtree, i, s);
	}

	int q;
	cin >> q;
	while(q--){
		int loc;
		cin >> loc;
		char type;
		cin >> type;
		s[loc-1] = type;
		update(segtree, loc, s);
		cout << segtree.back() << "\n";
	}
}

