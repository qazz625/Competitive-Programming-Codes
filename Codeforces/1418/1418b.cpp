/*
THINGS TO DO
1) Check integer overflows
2) Check corner cases
3) Compile and run once on terminal
4) Code smart, not quick
*/

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, i, j;
		cin >> n;
		vector<int> arr(n), pos, neg;
		
		for(i=0; i<n; i++){
			cin >> arr[i];
		}

		int lock[n];
		for(i=0; i<n; i++){
			cin >> lock[i];
		}


		int negsum=0, possum = 0;
		for(i=0; i<n; i++){
			if(arr[i] >= 0 && lock[i] == 0){
				pos.push_back(arr[i]);
				possum += arr[i];
			}
			else if(arr[i] < 0 && lock[i] == 0){
				neg.push_back(arr[i]);
				negsum += arr[i];
			}
		}

		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());

		for(i=0; i<pos.size(); i++){
			cout << pos[i] << " ";
		}
		cout << endl;
		for(i=0; i<neg.size(); i++){
			cout << neg[i] << " ";
		}
		cout << endl;

		
		int indp=0, indn=0, position = 0;
		vector<int> temp = arr;

		possum = 0;
		while(indp != pos.size() && possum + pos[indp] < negsum){
			if(lock[position] == 1){
				position++;
				continue;
			}
			temp[position] = pos[indp];
			position++;
			indp++;
		}

	}


}

//Read the stuff at the top