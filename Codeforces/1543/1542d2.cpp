#include <bits/stdc++.h> 
using namespace std;

#define int long long

int n, base, lim;

vector<int> decToBase(int num){
	vector<int> ret(lim);
	for(int i=0; i<lim; i++){
		ret[i] = num%base;
		num /= base;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int baseToDec(vector<int> &v){
	int mult = 1;
	int ret = 0;
	for(int i=lim-1; i>=0; i--){
		ret += mult*v[i];
		mult *= base;
	}
	return ret;
}

int32_t main(){
	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++){
		cin >> n >> base;
		cout << 0 << endl;
		int r;
		cin >> r;
		if(r == 1){
			continue;
		}

		int temp = 1;
		lim = 0;
		while(temp < (1<<18)){
			temp *= base;
			lim++;
		}

		for(int i=1; i<n; i++){
			vector<int> prev = decToBase(i-1);
			vector<int> cur = decToBase(i);
			vector<int> q(lim);
			if(i%2 == 1){
				for(int i=0; i<lim; i++){
					int num = ((prev[i]-cur[i])%base + base)% base;
					q[i] = num;
				}
			}
			else{
				for(int i=0; i<lim; i++){
					int num = ((cur[i]-prev[i])%base + base)% base;
					q[i] = num;
				}
			}
			
			int num = baseToDec(q);
			cout << num << endl;
			cin >> r;
			if(r == 1)
				break;
		}
	}
}
