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
		int n;
		cin >> n;
		int first;
		cin >> first;
		multiset<pair<int, int>> s;
		for(int i=1; i<n; i++){
			int x;
			cin >> x;
			s.insert({x, i});
		}

		vector<vector<int>> ans;
		while(s.size() != 0){
			pair<int, int> num = *(s.begin());
			if(num.first > first && s.size() == 1){
				break;
			}

			else if(num.first <= first){
				s.erase(s.begin());
				ans.push_back({num.second, 0, num.first});
				first += num.first;
			}

			else{
				s.erase(s.begin());
				pair<int, int> num2 = *(s.begin());
				s.erase(s.begin());

				int transfer = num.first - first;
				ans.push_back({num.second, num2.second, transfer});
				num2.first += (num.first-first);

				ans.push_back({num.second, 0, first});
				first *= 2;
				s.insert(num2);
			}
		}

		if(s.size() != 0){
			cout << "-1\n";
		}
		else{
			cout << ans.size() << "\n";
			for(auto x: ans){
				cout << x[0]+1 << " " << x[1]+1 << " " << x[2] << "\n";
			}
		}
	}
}
