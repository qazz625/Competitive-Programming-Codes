/*
THINGS TO DO
1) Check integer overflows
2) Check corner cases
3) Compile and run once on terminal
4) Code smart, not quick
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int n, p;
	cin >> n >> p;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);

	map<int, vector<int>> mp;

	for(int i=0; i<n; i++){
		int cur = arr[i];
		while(true){
			if(cur == 1 || cur%4 == 2)
				break;

			if(cur%4 == 0)
				cur /= 4;
			if(cur != 1 && cur%2 == 1)
				cur /= 2;
		}
		mp[cur].push_back(arr[i]);
	}

	for(auto &x: mp){
		set<int> s;
		for(auto y: x.second){
			s.insert(y);
		}
		vector<int> newarr;
		for(int i=x.second.size()-1; i>=0; i--){
			int cur = x.second[i];
			int flag = 0;
			while(cur != 1 && cur%4 != 2){
				if(cur%4 == 0)
					cur /= 4;
				else if(cur != 1 && cur%2 == 1)
					cur /= 2;

				if(s.find(cur) != s.end()){
					flag = 1;
					break;
				}
			}
			if(flag == 0)
				newarr.push_back(x.second[i]);
		}
		x.second = newarr;
	}

	for(auto x: mp){
		cout << x.first << ": ";
		print(x.second);
	}


}

//Read the stuff at the top