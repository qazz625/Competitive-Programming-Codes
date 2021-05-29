#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int x, n;
		cin >> x >> n;
		if(n%x != 0){
			cout << "-1\n";
			continue;
		}

		n /= x;

		int ans = 10000000;
		for(int i=1; i<=60; i++){
			int num = n+i;
			int curans = __builtin_popcountll(num);
			if(curans == i){
				for(int j=0; j<=60; j++)
					if((1ll<<j)&num)
						curans += j;
				ans = min(ans, curans-1);
			}
		}
		if(ans == 10000000)
			cout << "-1\n";
		else
			cout << ans << "\n";
	}
}

