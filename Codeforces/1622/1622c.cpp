#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n, k;


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		sort(arr, arr+n);


		int total = 0;
		for(int i=0; i<n; i++){
			total += arr[i];
		}

		int sub = 0;

		int s = -1ll<<60, e = arr[0], ans = 1ll<<60;
		int changed = 1;
		sub += arr[0];
		while(s <= e){
			int mid = (s+e)/2;
			int add = changed*mid;
			if(total-sub+add <= k){
				s = mid+1;
				ans = arr[0]-mid;
			}
			else{
				e = mid-1;
			}
		}

		for(int i=n-1; i>=1; i--){
			int s = -1ll<<60, e = arr[0], curans = 1ll<<60;
			int changed = n-i + 1;
			sub += arr[i];
			while(s <= e){
				int mid = (s+e)/2;
				int add = changed*mid;
				if(total-sub+add <= k){
					s = mid+1;
					curans = arr[0]-mid+(changed-1);
				}
				else{
					e = mid-1;
				}
			}
			ans = min(ans, curans);
		}
		cout << ans << "\n";
	}
}

