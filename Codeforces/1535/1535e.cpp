#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int stable[300010][20];
int totcost[300010], totgold[300010];

int32_t main(){
	int q, a, c;
	cin >> q >> a >> c;

	for(int i=0; i<20; i++){
		stable[0][i] = -1;
	}

	totcost[0] = c;
	totgold[0] = a;

	// print(totcost, 5);
	// print(totgold, 5);

	for(int qq=1; qq<=q; qq++){
		int type;
		cin >> type;
		if(type == 1){
			int p, a, c;
			cin >> p >> a >> c;

			int ind = qq;
			totcost[qq] = c;
			totgold[qq] = a;
			stable[ind][0] = p;

			for(int i=1; i<20; i++){
				if(stable[ind][i-1] != -1 && stable[stable[ind][i-1]][i-1] != -1){
					stable[ind][i] = stable[stable[ind][i-1]][i-1];
				}
			}
		}

		else{
			int oriv, oriw;
			cin >> oriv >> oriw;
			int w = oriw;
			int ans = 0;
			while(true){
				int v = oriv;
				if(totgold[v] == 0 || w == 0){
					break;
				}

				for(int i=19; i>=0; i--){
					if(stable[v][i] != -1){
						if(totgold[stable[v][i]] != 0){
							v = stable[v][i];
						}
					}
				}
				if(w >= totgold[v]){
					w -= totgold[v];
					ans += totgold[v]*totcost[v];
					totgold[v] = 0;
				}
				else{
					ans += w*totcost[v];
					totgold[v] -= w;
					w = 0;
				}
			}
			cout << oriw-w << " " << ans << "\n";
		}
	}
}
