#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int x, y, a, b;

int solve(int num, int x, int y, int a, int b){
	x -= num*a;
	y -= num*b;

	if(y < 0)
		return -10000000000000;
	else
		return min(x/b, y/a);
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> x >> y >> a >> b;

		//how many (a, b) pairs
		int s = 0, e = min(x/a, y/b), ans = -1;
		// debug(s, e);
		while(s <= e){
			int offset = (e-s)/3;
			int m1 = s + offset;
			int m2 = e - offset;

			int one = solve(m1, x, y, a, b);
			int two = solve(m2, x, y, a, b);

			debug(m1, m2, one, two);

			if(one+m1 > two+m2){
				ans = one+m1;
				e = m2-1;
			}
			else{
				ans = two+m2;
				s = m1+1;
			}
		}
		assert(ans != -1);
		cout << ans << "\n";
	}


}
