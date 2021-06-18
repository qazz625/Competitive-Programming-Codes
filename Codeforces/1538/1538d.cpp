#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int factors(int n){
	int ans = 0;
	for(int i=2; i*i <= n; i++){
		while(n%i == 0){
			n /= i;
			ans++;
		}
	}
	if(n != 1)
		ans++;
	return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int a, b, k;
		cin >> a >> b >> k;
		if(a > b)
			swap(a, b);

		if(k == 1){
			if(b%a == 0 && a != b)
				cout << "YES\n";
			else
				cout << "NO\n";
			continue;
		}

		int afact = factors(a);
		int bfact = factors(b);

		if(afact + bfact >= k)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
