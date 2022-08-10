#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
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
		int matrix[2][n];
		for(int i=0; i<2; i++)
			for(int j=0; j<n; j++)
				cin >> matrix[i][j];

		vector<int> arr1, arr2;
		for(int i=0; i<n; i++)
			arr1.push_back(matrix[0][i]);
		for(int i=n-1; i>=0; i--)
			arr1.push_back(matrix[1][i]);

		for(int i=1; i<n; i++)
			arr2.push_back(matrix[1][i]);
		for(int i=n-1; i>=1; i--)
			arr2.push_back(matrix[0][i]);

		print(arr1);
		print(arr2);

		int ans1 = -1, ans2 = -1;
		vector<int> arr1ans(arr1.size());
		int arr1maxwaitind = -1;
		for(int i=1; i<arr1.size(); i++){
			if(arr1[i] >= arr1ans[i]+1)
				arr1maxwaitind = i; 
			arr1ans[i] = max(arr1[i], arr1ans[i-1]+1);
		}

		vector<int> arr2ans(arr2.size());
		int arr2maxwaitind = -1;
		arr2ans[0] = max(arr2[0], max(1, matrix[1][0])+1);
		for(int i=1; i<arr2.size(); i++){
			if(arr2[i] >= arr2ans[i]+1)
				arr2maxwaitind = i; 
			arr2ans[i] = max(arr2[i], arr2ans[i-1]+1);
		}


		print(arr1ans);
		print(arr2ans);

		int ans = max(arr2ans.back(), arr1ans.back());
		int curwait = max(1, matrix[1][0])+1;
		for(int i=2; i<n; i++){
			if(i%2 == 0){
				curwait = max(curwait+1, matrix[1][i]);
				curwait = max(curwait+1, matrix[0][i]);
			}
			else{
				curwait = max(curwait+1, matrix[0][i]);
				curwait = max(curwait+1, matrix[1][i]);
			}
			debug(i, curwait);

		}

				cout << "\n\n";



	}


}

//Read the stuff at the top