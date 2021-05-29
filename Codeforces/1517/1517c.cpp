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
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	int ans[n][n];
	for(int i=0; i<n; i++){
		vector<int> temp;
		set<int> s;
		for(int j=n-i; j<=n; j++){
			s.insert(j);
		}

		for(int j=0; j<n; j++){
			if(s.find(arr[j]) != s.end()){
				temp.push_back(arr[j]);
			}
		}

		int col = 0;
		for(int j=n-i-1, col=0; j<n; j++, col++){
			// debug(i, col);
			ans[j][col] = temp[col];
		}

		// print(temp);
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}
