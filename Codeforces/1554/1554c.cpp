/*
THINGS TO DO
1) Check integer overflows
2) Check corner cases
3) Compile and run once on terminal
4) Code smart, not quick
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		if(m < n){
			cout << "0\n";
			continue;
		}
		if(n == 0){
			cout << m+1 << "\n";
			continue;
		}

		int lmb;
		for(int i=0; i<=30; i++){
			if((1<<i)&m)
				lmb = i;
		}

		int prefunmatch = 0;
		int ind = -1, oriind = -1;
		for(int i=lmb; i>=0; i--){
			int two = !((1<<i)&n);

			// debug(one, two, i, (1<<i)&n, n);
			if(two)
				prefunmatch++;
			else{
				ind = i;
				oriind = i;
				break;
			}
		}


		int newm = 0, newn = 0;
		for(int i=0; i<lmb+1-prefunmatch; i++){
			newm += (1<<i)&m;
			newn += (1<<i)&n;
		}
		// debug(ind);

		// debug(prefunmatch, newm, newn, ind);

		int toadd = 0;
		if(newm < newn){
			toadd = 0;
		}
		else{
			// newm++;
			// debug(newm, newn);
			int flag = 0;
			int done[30] = {0};
			for(int i=0; i<=30; i++){
				int one = (1<<i)&newm;
				int two = !((1<<i)&newn);
				debug(one, two);
				if((one && two)){
					toadd += (1<<i);
					done[i] = 1;
					for(int j=i; j>=0; j--){
						// int three = !((1<<j)&newm);
						// int four = (1<<j)&newn;
						// debug(i, j, three, four);
						if(done[j] == 0){
							done[j] = 1;
							toadd += (1<<j);
						}
					}
				}
				debug(i, toadd);
			}
		}
		debug(oriind, lmb, toadd);

		for(int i=lmb; i>oriind; i--){
			toadd += (1<<i)&m;
		}

		cout << toadd << "\n";
	}


}

//Read the stuff at the top