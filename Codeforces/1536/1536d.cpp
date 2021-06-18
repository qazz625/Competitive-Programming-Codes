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
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		set<int> s;
		s.insert(arr[0]);

		string ans = "YES";
		for(int i=1; i<n; i++){
			s.insert(arr[i]);
			auto itr = s.find(arr[i-1]);
			if(arr[i] > arr[i-1]){
				auto ptr = itr;
				ptr++;
				if(ptr == s.end() || *ptr != arr[i]){
					ans = "NO";
				}
			}
			else if(arr[i] < arr[i-1]){
				auto ptr = itr;
				if(ptr == s.begin()){
					ans = "NO";
				}
				ptr--;
				if(*ptr != arr[i]){
					ans = "NO";
				}
			}
		}
		cout << ans << "\n";
	}
}
