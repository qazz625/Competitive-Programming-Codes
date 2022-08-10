#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n;

vector<pair<int, int>> buildSegTree(vector<int> &arr, int flag){
	vector<pair<int, int>> segtree(2*arr.size());
	for(int i=0; i<n; i++)
		segtree[i+n] = {arr[i], i};


	for(int i=segtree.size()-1; i!=1; i-=2){
		if(flag == 0){
			segtree[i/2] = min(segtree[i], segtree[i-1]);
		}
		else{
			segtree[i/2] = max(segtree[i], segtree[i-1]);
		}
	}

	return segtree;
}

pair<int, int> query(vector<pair<int, int>> &segtree, int x, int y, int l, int r, int ind, int op){
	if(l > y || r < x){
		if(op == 0)
			return {1ll<<60, -1};
		else
			return {-(1ll<<60), -1};
	}
	else if(x >= l && y <= r){
		return segtree[ind];
	}
	else{
		int mid = (x+y)/2;
		pair<int, int> val1 = query(segtree, x, mid, l, r, 2*ind, op);
		pair<int, int> val2 = query(segtree, mid+1, y, l, r, 2*ind+1, op);
		if(op == 0)
			return min(val1, val2);
		else
			return max(val1, val2);
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> arr(n+1);
		n++;
		arr[0] = 1<<30;
		for(int i=1; i<n; i++)
			cin >> arr[i];

		while((1<<30)%n != 0){
			arr.push_back(0);
			n++;
		}


		vector<int> pref(n);
		
		pref[0] = arr[0];
		for(int i=1; i<n; i++)
			pref[i] = pref[i-1]+arr[i];
		// print(arr);
		// print(pref);

		vector<pair<int, int>> minsegtree = buildSegTree(pref, 0);
		vector<pair<int, int>> maxsegtree = buildSegTree(pref, 1);

		// print(minsegtree);
		// print(maxsegtree);

		vector<int> next(n);
		vector<int> prev(n);

		vector<pair<int, int>> nge;
		for(int i=n-1; i>=0; i--){
			while(nge.size() != 0 && nge.back().first <= arr[i]){
				nge.pop_back();
			}
			if(nge.size() == 0){
				next[i] = -1;
			}
			else{
				next[i] = nge.back().second;
			}
			nge.push_back({arr[i], i});
		}

		vector<pair<int, int>> pge;
		for(int i=0; i<n; i++){
			while(pge.size() != 0 && pge.back().first <= arr[i]){
				pge.pop_back();
			}
			if(pge.size() == 0){
				prev[i] = -1;
			}
			else{
				prev[i] = pge.back().second;
			}
			pge.push_back({arr[i], i});
		}
		// print(next);
		// print(prev);

		int flag = 0;

		for(int i=1; i<n; i++){
			int l, r;
			if(prev[i] == -1)
				l = 0;
			else
				l = prev[i]+1;
			if(next[i] == -1)
				r = n-1;
			else
				r = next[i]-1;

			// debug(l, r);

			pair<int, int> ans1 = query(minsegtree, 0, n-1, l, i, 1, 0);
			pair<int, int> ans2 = query(maxsegtree, 0, n-1, i, r, 1, 1);

			// print(ans1);
			// print(ans2);

			if(pref[i]-pref[ans1.second-1] <= arr[i] && pref[ans2.second]-pref[i-1] <= arr[i]){
				//do nothing
			}
			else{
				// print(ans1);
				// print(ans2);
				// debug(pref[i]-pref[(ans1.second-1)]);
				// debug(i, pref[i], pref[i]-ans1, ans2-pref[i]);
				flag = 1;
			}
			// cout << "\n";
		}

		if(flag == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}

	}
}

