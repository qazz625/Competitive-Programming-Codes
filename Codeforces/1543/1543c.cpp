#include <bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

double c, m, p, v;

double epsilon = 1e-12;

double solve(int num, int l, double c, double m, double p, double v){

	int mvalid = 1, cvalid = 1;
	double prob = 1;
	for(int i=0; i<l; i++){
		//0 for c
		if((num&(1<<i)) == 0){
			if(c <= epsilon){
				return 0;
			}
			else if(c < v || abs(c-v) <= epsilon){
				prob *= c;
				if(mvalid == 1){
					m += c/2;
					p += c/2;
				}
				else{
					p += c;
				}
				c = 0;
				cvalid = 0;
			}
			else{
				prob *= c;
				if(mvalid == 1){
					m += v/2;
					p += v/2;
				}
				else{
					p += v;
				}
				c -= v;
			}
		}

		//1 for m
		else{
			if(m <= epsilon){
				return 0;
			}
			else if(m < v || abs(m-v) <= epsilon){
				prob *= m;
				if(cvalid == 1){
					c += m/2;
					p += m/2;
				}
				else{
					p += m;
				}
				
				m = 0;
				mvalid = 0;
			}
			else{
				prob *= m;
				if(cvalid == 1){
					c += v/2;
					p += v/2;
				}
				else{
					p += v;
				}
				m -= v;
			}
		}
		// debug(i, c, m, p, v);
	}
	prob *= p;
	// debug("NOTzero");

	return prob;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> c >> m >> p >> v;

		double ans = p;
		//CHANGE l LIMIT
		for(int l = 1; l<=19; l++){
			double tot = 0;
			for(int i=0; i<(1<<l); i++){
				double temp = solve(i, l, c, m, p, v);
				tot += temp;
			}
			// debug(tot);
			// cout << "\n";
			ans += (l+1)*tot;
		}
		cout << setprecision(12) << ans << "\n";
	}
}
