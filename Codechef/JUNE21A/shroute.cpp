#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int inf = 1e18 + 20;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int arr[n];
		vector<int> one, two;
		vector<int> direct(n, 0);
		for(int i=0; i<n; i++){
			cin >> arr[i];
			if(arr[i] == 1){
				one.push_back(i);
				direct[i] = 1;
			}
			else if(arr[i] == 2){
				two.push_back(i);
				direct[i] = 1;
			}
		}

		for(int i=0; i<m; i++){
			int dest;
			cin >> dest;
			dest--;

			if(direct[dest] == 1 || dest == 0){
				cout << "0 ";
				continue;
			}

			int a, b;
			auto ptr = lower_bound(one.begin(), one.end(), dest);
			if(ptr == one.begin())
				a = inf;
			else{
				ptr--;
				a = dest-(*ptr);
			}

			auto ptr2 = upper_bound(two.begin(), two.end(), dest);
			if(ptr2 == two.end())
				b = inf;
			else{
				b = (*ptr2)-dest;
			}

			int ans = min(a, b);
			if(ans == inf)
				cout << "-1 ";
			else
				cout << ans << " ";

		}
		cout << "\n";
	}
}

