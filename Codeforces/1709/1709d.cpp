#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int query(vector<int> &segtree, int x, int y, int l, int r, int ind){
	// debug(x, y, l, r);
	if(y < l || x > r){
		return -1;
	}
	else if(x >= l && y <= r){
		return segtree[ind];
	}
	else{
		int mid = (x+y)/2;
		int a = query(segtree, x, mid, l, r, 2*ind);
		int b = query(segtree, mid+1, y, l, r, 2*ind+1);
		return max(a, b);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> arr(m);
	for(int i=0; i<m; i++)
		cin >> arr[i];

	while((1<<30)%arr.size() != 0){
		arr.push_back(0);
		m++;
	}

	vector<int> segtree(2*m);
	for(int i=0; i<m; i++){
		segtree[i+m] = arr[i];
	}

	for(int i=segtree.size()-1; i!=1; i-=2){
		segtree[i/2] = max(segtree[i], segtree[i-1]);
	}

	// print(arr);
	// print(segtree);

	int q;
	cin >> q;
	while(q--){
		int ns, ms, nf, mf, k;
		cin >> ns >> ms >> nf >> mf >> k;
		ns = n-ns+1;
		nf = n-nf+1;
		if(ms > mf){
			swap(ns, nf);
			swap(ms, mf);
		}


		if(abs(ns-nf)%k != 0 || abs(ms-mf)%k != 0){
			cout << "NO\n";
			continue;
		}

		int maxval = ns - k*(ns/k);

		if(maxval == 0)
			maxval += k;

		int maxblock = n-maxval;

		int curmax = query(segtree, 0, m-1, ms-1, mf-1, 1);

		// debug(maxval, maxblock, curmax);

		// debug(ns, ms);
		// debug(nf, mf);
		if(curmax > maxblock){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}

}

