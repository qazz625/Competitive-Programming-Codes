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
		vector<vector<int>> arr(n, vector<int>(5));

		for(int i=0; i<n; i++){
			for(int j=0; j<5; j++)
				cin >> arr[i][j];
		}

		vector<int> cur = arr[0];

		int ind = 0;
		for(int i=1; i<n; i++){
			int tot = 0;
			for(int j=0; j<5; j++){
				if(cur[j] < arr[i][j])
					tot += 1;
				else
					tot -= 1;
			}

			if(tot < 0){
				cur = arr[i];
				ind = i;
			}
		}

		int flag = 0;
		for(int i=0; i<n; i++){
			if(ind != i){
				int tot = 0;
				for(int j=0; j<5; j++){
					if(cur[j] < arr[i][j])
						tot += 1;
					else
						tot -= 1;
				}

				if(tot < 0)
					flag = 1;
			}
		}

		if(flag == 1){
			cout << -1 << "\n";
		}
		else{
			cout << ind+1 << "\n";
		}

	}
}

