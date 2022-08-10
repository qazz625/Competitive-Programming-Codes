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
		vector<int> arr;
		int pos = 0;
		int neg = 0;
		int zero = 0;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			if(x > 0){
				pos++;
				arr.push_back(x);
			}
			else if(x < 0){
				neg++;
				arr.push_back(x);
			}
			else
				zero++;
		}



		if(pos >= 3 || neg >= 3){
			cout << "NO\n";
			continue;
		}

		for(int i=0; i<min(3, zero); i++){
			arr.push_back(0);
		}

		set<int> s;
		for(auto x: arr)
			s.insert(x);

		n = arr.size();

		int flag = 0;
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				for(int k=j+1; k<n; k++)
					if(s.find(arr[i] + arr[j] + arr[k]) == s.end())
						flag = 1;


		// print(arr);

		if(flag == 1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
}
