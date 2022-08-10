#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int solve(int arr[], int n, int val){
	int ptr1 = 0, ptr2 = n-1;
	// debug(val);
	while(ptr1 <= ptr2){
		if(arr[ptr1] == arr[ptr2]){
			ptr1++;
			ptr2--;
		}
		else if(arr[ptr1] == val){
			ptr1++;
		}
		else if(arr[ptr2] == val){
			ptr2--;
		}
		else{
			return 0;
		}
	}
	return 1;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		// print(arr, n);

		int ptr1 = 0, ptr2 = n-1;
		while(ptr1 <= ptr2){
			if(arr[ptr1] == arr[ptr2]){
				ptr1++;
				ptr2--;
			}
			else{
				break;
			}
		}
		// debug(ptr1, ptr2);

		if(ptr1 > ptr2){
			cout << "YES\n";
			continue;
		}

		int one = solve(arr, n, arr[ptr1]);
		int two = solve(arr, n, arr[ptr2]);
		if(one || two){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}


}

