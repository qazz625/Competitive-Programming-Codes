#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int MAX = 400000;

int findSq(int a){
	if(a > 1e18)
		return a;

	int s = 0, e = 1e9;
	int ans = -1;	
	while(s <= e){
		int mid = (s+e)/2;
		if(mid*mid <= a){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	return ans;
}


int32_t main(){
	int t;
	cin >> t;

	vector<int> a;
	for(int i=3; i<MAX; i+=2){
		a.push_back(i);
	}

	vector<int> b;
	for(int i=0; i<a.size(); i++){
		b.push_back((a[i]*a[i]-1)/2);
	}
	
	while(t--){
		int n;
		cin >> n;

		int s = 0, e = a.size()-1;
		int ans = -1;
		while(s <= e){
			int mid = (s+e)/2;
			bool c1 = a[mid] <= n;
			bool c2 = b[mid] <= n;
			bool c3 = findSq(a[mid]*a[mid] + b[mid]*b[mid]) <= n;
			if(c1 && c2 && c3){
				ans = mid;
				s = mid+1;
			}
			else{
				e = mid-1;
			}
		}

		cout << ans+1 << "\n";
	}
}