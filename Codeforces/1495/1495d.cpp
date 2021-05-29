#include <bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];

	if(n <= 2){
		cout << "0\n";
		return 0;
	}

	int candidate = -1;	
	for(int i=1; i<n-1; i++){
		if(arr[i] > arr[i+1] && arr[i] > arr[i-1]){
			int ind = i-1;
			while(ind != -1 && arr[ind] < arr[ind+1])
				ind--;

			int one = i-ind;
			ind = i+1;
			while(ind != n && arr[ind] < arr[ind-1])
				ind++;
			int two = ind-i;
			// debug(one, two);
			if(one == two && one%2 != 0){
				candidate = max(candidate, one);
			}
		}
	}
	// debug(candidate);

	if(candidate == -1){
		cout << "0\n";
		return 0;
	}

	map<int, int> mp;
	vector<int> v = {0};
	for(int i=1; i<n-1; i++){
		if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
			v.push_back(i);
		if(arr[i] < arr[i-1] && arr[i] < arr[i+1])
			v.push_back(i);
	}
	v.push_back(n-1);
	// print(v);

	for(int i=1; i<v.size(); i++){
		mp[abs(v[i]-v[i-1])+1]++;
	}

	// print(mp);
	int lol = (--mp.end())->first;

	if(lol > candidate || mp[lol] >= 3){
		cout << "0\n";
	}
	else{
		cout << "1\n";
	}
}
