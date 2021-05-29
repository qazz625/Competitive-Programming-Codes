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
		int n, m;
		cin >> n >> m;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		int prefsum[n];
		prefsum[0] = arr[0];
		for(int i=1; i<n; i++)
			prefsum[i] = prefsum[i-1]+arr[i];

		int prefmax[n];
		prefmax[0] = prefsum[0];

		for(int i=1; i<n; i++)
			prefmax[i] = max(prefmax[i-1], prefsum[i]);

		while(m--){
			int goal;
			cin >> goal;
			if(prefsum[n-1] <= 0 && prefmax[n-1] < goal){
				cout << "-1 ";
				continue;
			}

			int loops;
			if(prefmax[n-1] >= goal)
				loops = 0;
			else{
				loops = (goal - prefmax[n-1])/prefsum[n-1];
				if((goal-prefmax[n-1])%prefsum[n-1] != 0)
					loops++;
			}

			int rem = goal - loops*prefsum[n-1];

			int s = 0, e = n-1, ans = -1;
			while(s <= e){
				int mid = (s+e)/2;
				if(prefmax[mid] >= rem){
					ans = mid;
					e = mid-1;
				}
				else{
					s = mid+1;
				}
			}

			cout << loops*n + ans << " ";
		}
		cout << "\n";
	}
}
