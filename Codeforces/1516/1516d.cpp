#include <bits/stdc++.h>
using namespace std;

int sieve[100010];
int stable[100010][18];

void solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=2; i<100010; i++)
		if(sieve[i] == 0)
			for(int j=i; j<=100010; j+=i)
				sieve[j] = i;

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

	int next[n] = {0};

	int ptr1 = 0, ptr2 = 0;
	map<int, int> curmap = arr[0];

	while(ptr2 != n){
		if(ptr1 > ptr2){
			ptr2++;
			if(ptr2 != n){
				for(auto x: arr[ptr2])
					curmap[x.first] += x.second;
			}
			continue;
		}

		ptr2++;
		int flag = 0;
		if(ptr2 != n){
			for(auto x: arr[ptr2]){
				if(curmap.find(x.first) != curmap.end()){
					flag = 1;
				}
			}
		}

		if(flag == 1){
			next[ptr1] = ptr2;
			for(auto x: arr[ptr1]){
				curmap[x.first] -= x.second;
				if(curmap[x.first] == 0)
					curmap.erase(x.first);
			}
			ptr1++;
			ptr2--;
		}
		else if(ptr2 != n){
			for(auto x: arr[ptr2])
				curmap[x.first] += x.second;
		}
	}

	for(; ptr1 != n; ptr1++){
		next[ptr1] = n;
	}

	// print(next, n);

	for(int i=0; i<n; i++){
		for(int j=0; j<18; j++){
			stable[i][j] = n;
		}
	}

	for(int i=0; i<n; i++){
		stable[i][0] = i;
		stable[i][1] = next[i];
	}

	for(int i=n-1; i>=0; i--)
		for(int j=2; j<18; j++)
			if(stable[i][j-1] != n && stable[stable[i][j-1]][j-1] != n)
				stable[i][j] = stable[stable[i][j-1]][j-1];

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
