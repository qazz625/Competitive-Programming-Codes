
#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int n, m;
	cin >> n >> m;
	string s;
	for(int i=0; i<m; i++)
		s += '0';

	vector<pair<int, int>> arr;

	for(int i=0; i<m; i++){
		s[i] = '1';
		cout << "? " << s << endl;
		int val;
		cin >> val;
		arr.push_back({val, i});
		s[i] = '0';
	}

	sort(arr.begin(), arr.end());

	// print(arr);

	int tot = 0;
	for(int i=0; i<m; i++){
		s[arr[i].second] = '1';
		cout << "? " << s << endl;
		int val;
		cin >> val;
		if(val-tot != arr[i].first){
			s[arr[i].second] = '0';
		}
		else{
			tot += arr[i].first;
		}
	}

	cout << "! " << tot << endl;
}

