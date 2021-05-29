#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n, m, x;
		cin >> n >> m >> x;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		multiset<pair<int, int>> ms;
		int ans[n] = {0};
		for(int i=0; i<m; i++){
			ms.insert({arr[i], i+1});
			ans[i] = i+1;
		}

		for(int i=m; i<n; i++){
			pair<int, int> fr = *ms.begin();
			ans[i] = fr.second;
			ms.erase(ms.begin());
			fr.first += arr[i];
			ms.insert(fr);

			pair<int, int> t1 = *ms.begin();
			pair<int, int> t2 = *(--ms.end());
			assert(abs(t1.first-t2.first) <= x);
		}

		cout << "YES\n";
		for(int i=0; i<n; i++)
			cout << ans[i] << " ";
		cout << "\n";

	}
}