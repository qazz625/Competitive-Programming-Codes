#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int x, y;
		cin >> x >> y;
		int n;
		if(x > y)
			n = x+y;
		else
			n = y-y%x/2;
		cout << n << "\n";
	}
}
