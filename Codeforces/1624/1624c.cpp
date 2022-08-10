#include <bits/stdc++.h>
using namespace std;

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
		multiset<int> arr;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			while(x > n)
				x /= 2;
			arr.insert(x);
		}


		int flag = 0;
		string ret = "YES\n";
		for(int i=n; i>=1; i--){
			int ans = -1;
			// print(arr);
			int flag = 0;
			for(auto x: arr){
				int num = x;
				while(num != 0 && num != i){
					num /= 2;
				}
				if(num != 0){
					flag = 1;
					ans = x;
					break;
				}
			}
			// debug(i, ans, flag);
			if(flag == 1)
				arr.erase(arr.find(ans));
			else{
				ret = "NO\n";
				break;
			}

		}

		cout << ret;
	}
}

