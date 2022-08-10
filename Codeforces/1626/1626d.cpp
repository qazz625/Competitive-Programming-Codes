#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n;
vector<int> twopow;
int findsum(vector<int> &pref, int s, int e){
	if(s == 0)
		return pref[e];
	else{
		return pref[e] - pref[s-1];
	}
}

int check(vector<int> &pref, vector<int> &arr, int start){
	if(start == n)
		return 2;

	else{
		// debug(start);
		int totsum = findsum(pref, start, n-1);
		int req = 1ll<<60;
		for(int i=0; i<20; i++){
			int s = start, e = n-1, ans = -1;
			// debug(s, e);
			while(s <= e){
				int mid = (s+e)/2;
				int val = findsum(pref, start, mid);
				// debug(s, mid, val);
				if(val <= (1<<i)){
					s = mid+1;
					ans = mid;
				}
				else{
					e = mid-1;
				}
			}
			// debug(ans);

			//middleweight is empty
			if(ans == -1){
				int add;
				for(int j=0; j<20; j++){
					if(twopow[j] >= totsum){
						add = twopow[j]-totsum;
						break;
					}
				}
				req = min(req, 1 + add);
			}

			else{
				int add1 = (1ll<<i) - findsum(pref, start, ans);
				int add2, remsum = totsum - findsum(pref, start, ans);
				for(int j=0; j<20; j++){
					if(twopow[j] >= remsum){
						add2 = twopow[j]-remsum;
						break;
					}
				}
				// debug(add1, add2);
				req = min(req, add1 + add2);
			}

			// debug(i, ans, req);
		}

		return req;

	}
}


int32_t main(){

	for(int i=0; i<20; i++){
		twopow.push_back(1ll<<i);
	}

	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n];

		map<int, int> mp;
		for(int i=0; i<n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}

		vector<int> arr;
		for(auto x: mp){
			arr.push_back(x.second);
		}


		n = arr.size();
		int p1 = 0;
		vector<int> pref(n);
		pref[0] = arr[0];
		for(int i=1; i<n; i++){
			pref[i] = pref[i-1] + arr[i];
		}

		int res = 1 + check(pref, arr, 0);

		for(int i=0; i<n; i++){
			p1 += arr[i];
			
			int add;
			for(int j=0; j<20; j++){
				if(twopow[j] >= p1){
					add = twopow[j]-p1;
					break;
				}
			}

			int ans = check(pref, arr, i+1);
			res = min(res, ans + add);
		}

		cout << res << "\n";
	}
}

