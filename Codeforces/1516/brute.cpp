#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int sieve[100010];
int stable[100010][18];

void solve(){
	for(int i=2; i<100010; i++){
		if(sieve[i] == 0){
			for(int j=i; j<=100010; j+=i){
				sieve[j] = i;
			}
		}
	}


	// print(sieve, 15);

	int n, q;
	cin >> n >> q;
	vector<map<int, int>> arr(n);
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		map<int, int> mp;
		while(num != 1){
			mp[sieve[num]]++;
			num /= sieve[num];
		}
		arr[i] = mp;
	}

	// for(auto x: arr){
	// 	print(x);
	// }

	int next[n] = {0};

	for(int i=0; i<n; i++){
		map<int, int> mp;
		int flag = 0;
		int ind = i;
		while(ind != n && flag == 0){
			for(auto x: arr[ind]){
				if(mp.find(x.first) != mp.end()){
					flag = 1;
				}
				else{
					mp[x.first] = x.second;
				}
			}
			if(flag != 1)
				ind++;
		}
		next[i] = ind;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<18; j++){
			stable[i][j] = n;
		}
	}

	// print(next, n);

	// print(next, n);
	for(int i=0; i<n; i++){
		stable[i][0] = i;
		stable[i][1] = next[i];
	}

	for(int i=n-1; i>=0; i--){
		for(int j=2; j<18; j++){
			if(stable[i][j-1] != n && stable[stable[i][j-1]][j-1] != n){
				stable[i][j] = stable[stable[i][j-1]][j-1];
			}
		}
	}

	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<4; j++){
	// 		cout << stable[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	while(q--){
		int l, r;
		cin >> l >> r;
		l--; r--;
		int cur = l;
		int ans = 0;
		for(int i=17; i>0; i--){
			if(stable[cur][i] <= r){
				cur = stable[cur][i];
				ans += 1<<(i-1);
			}
		}
		cout << ans+1 << "\n";
	}
}


int main(){
		ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}