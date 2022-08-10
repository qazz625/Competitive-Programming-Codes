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
		int s, n;
		cin >> s >> n;

		vector<int> ans;
		while(ans.size() != n-1){

			while(ans.size() != n-1 && s%10 != 0){
				ans.push_back(1);
				s -= 1;
			}
			if(ans.size() == n-1)
				break;

			int tot = 0;
			int num = s;
			while(num != 0){
				tot += num%10;
				num /= 10;
			}
			int cursize = ans.size();

			if(tot >= (n-cursize)){
				int prod = 10;
				while(ans.size() != n-1){
					while(s%(10*prod) == 0)
						prod *= 10;
					ans.push_back(prod);
					s -= prod;
				}
			}

			else{
				int cur = 10;
				while(s%(10*cur) == 0){
					cur *= 10;
				}

				s -= cur;
				s += (cur-cur/10);
				// debug(s);
				ans.push_back(cur/10);
				// print(ans);
			}
		}

		ans.push_back(s);
		for(auto x: ans){
			cout << x << " ";
		}
		cout << "\n";
	}
}

