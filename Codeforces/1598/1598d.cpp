#include <bits/stdc++.h> 
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr[n+5];
		vector<int> arr2[n+5];

		for(int i=0; i<n; i++){
			int a, b;
			cin >> a >> b;
			arr[a].push_back(b);
			arr2[b].push_back(a);
		}

		map<int, int> front, end;

		int totalfront = 0, totalend = 0;
		for(auto x: arr[0]){
			front[x]++;
			totalfront++;
		}

		for(int i=2; i<n+5; i++){
			for(auto x: arr[i]){
				end[x]++;
				totalend++;
			}
		}

		int totaleq = 0;
		for(auto x: front){
			if(end.find(x.first) != end.end()){
				totaleq += x.second * end[x.first];
			}
		}

		int difftopic = 0;

		int ans = 0;
		for(int i=1; i<n; i++){
			for(auto x: arr[i]){
				int ft, et;
				if(front.find(x) == front.end())
					ft = totalfront;
				else
					ft = totalfront - front[x];

				if(end.find(x) == end.end())
					et = totalend;
				else
					et = totalend - end[x];


				int curtot = ft*et - totaleq + front[x]*end[x];
				// debug(i, x, curtot);
				ans += curtot;
				difftopic += totalfront*totalend;
			}

			set<int> s;
			for(auto x: arr[i])
				s.insert(x);
			for(auto x: arr[i+1])
				s.insert(x);

			int subtract = 0;
			for(auto x: s){
				subtract += front[x]*end[x];
			}

			for(auto x: arr[i]){
				front[x]++;
				totalfront++;
			}
			for(auto x: arr[i+1]){
				end[x]--;
				totalend--;
			}

			int add = 0;
			for(auto x: s){
				add += front[x]*end[x];
			}

			totaleq -= subtract;
			totaleq += add;
			// cout << "\n\n";
		}

		// debug(ans);

		int diffdiff = 0;
		totalfront = 0; totalend = 0;
		for(auto x: arr2[0]){
			totalfront++;
		}

		for(int i=2; i<n+5; i++){
			for(auto x: arr2[i]){
				totalend++;
			}
		}

		for(int i=1; i<n; i++){
			for(auto x: arr2[i]){
				diffdiff += totalfront*totalend;
			}

			for(auto x: arr2[i]){
				totalfront++;
			}
			for(auto x: arr2[i+1]){
				totalend--;
			}
		}

		cout << difftopic+diffdiff - ans << "\n";

	}
}

