#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];

	int mat[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			mat[i][j] = 0;

	for(int i=1; i<n; i++){
		for(int j=0; j<m-1; j++){
			if(arr[i][j] == 'X' && arr[i-1][j+1] == 'X')
				mat[i][j] = 1;
		}
	}

	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<m; j++){
	// 		cout << mat[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";

	for(int i=0; i<n; i++){
		for(int j=1; j<m; j++){
			mat[i][j] += mat[i][j-1];
		}
	}
	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<m; j++){
	// 		cout << mat[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";

	for(int i=1; i<n; i++){
		for(int j=0; j<m; j++)
			mat[i][j] += mat[i-1][j];
	}
	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<m; j++){
	// 		cout << mat[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";

	int q;
	cin >> q;
	while(q--){
		int col1, col2;
		cin >> col1 >> col2;
		col1--; col2--;

		if(n == 1 || col1 == col2){
			cout << "YES\n";
			continue;
		}

		col2--;

		//check sum from col1 to col2
		int sum;
		if(col1 == 0){
			sum = mat[n-1][col2];
		}
		else{
			sum = mat[n-1][col2] - mat[n-1][col1-1];
		}

		if(sum == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}


	}


}

//Read the stuff at the top