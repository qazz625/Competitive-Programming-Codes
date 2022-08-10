#include <bits/stdc++.h>
using namespace std;

#define int long long

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
		int n;
		cin >> n;
		vector<vector<int>> caves(n);
		vector<pair<int, int>> arr;
		for(int i=0; i<n; i++){
			int num;
			cin >> num;
			for(int j=0; j<num; j++){
				int x;
				cin >> x;
				caves[i].push_back(x);
			}

			int s = 0, e = 1000000001, ans = -1;
			while(s <= e){
				int mid = (s+e)/2;
				int ind = 0;
				int power = mid;
				for(ind = 0; ind<num; ind++){
					if(power > caves[i][ind])
						power++;
					else
						break;
				}
				if(ind == num){
					ans = mid;
					e = mid-1;
				}
				else{
					s = mid+1;
				}
			}
			arr.push_back({ans, num});
		}
		// print(arr);
		sort(arr.begin(), arr.end());

		int s = 0, e = 1<<30, ans = -1;
		while(s <= e){
			int mid = (s+e)/2;
			int ind = 0;
			int power = mid;
			for(ind = 0; ind<n; ind++){
				if(power >= arr[ind].first)
					power += arr[ind].second;
				else
					break;
			}
			if(ind == n){
				ans = mid;
				e = mid-1;
			}
			else{
				s = mid+1;
			}
		}

		cout << ans << "\n";


	}
}
