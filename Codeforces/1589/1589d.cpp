#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int check(int n){
	int s = 0, e = 1ll<<31, ans = -1;
	while(s <= e){
		int mid = (s+e)/2;
		if(mid*(mid+1) <= n){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}

	if(ans*(ans+1) == n){
		return ans;
	}
	return -1;
	
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int s = 1, e = n, ans = -1, res;
		while(s <= e){
			int mid = (s+e)/2;
			cout << "? " << 1 << " " << mid << endl;
			cin >> res;
			int c = check(res*2);
			// debug(c);

			if(c != -1){
				ans = mid;
				s = mid+1;
			}
			else{
				e = mid-1;
			}
		}

		int ans1 = ans;

		if(ans != 1){
			cout << "? " << ans-1 << " " << ans << endl;
			cin >> res;
			if(res == 0){
				ans--;
			}
		}
		// debug(ans);

		cout << "? " << 1 << " " << ans << endl;
		cin >> res;

		int a = check(2*res) + 1;
		// debug(a, ans);
		int l = ans - (a-1);
		int m = ans+1;

		cout << "? " << ans+1 << " " << n << endl;
		cin >> res;

		int b = check(2*res) + 1;
		int k = ans+1 + (b-1);

		if(k == 10007)
			cout << "! " << a << " " << b << " " << ans1 << endl;
		else
			cout << "! " << l << " " << m << " " << k << endl;

	}


}
