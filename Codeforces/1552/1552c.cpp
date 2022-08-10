#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		vector<pair<int, int>> arr(k);
		int used[2*n] = {0};
		int tot = 0;
		for(int i=0; i<k; i++){
			cin >> arr[i].first >> arr[i].second;
			arr[i].first--; arr[i].second--;
			used[arr[i].first] = 1;
			used[arr[i].second] = 1;
		}

		// debug(tot);

		for(int i=0; i<k; i++){
			for(int j=i+1; j<k; j++){
				vector<pair<int, int>> temp;
				temp.push_back({arr[i].first, i});
				temp.push_back({arr[i].second, i});
				temp.push_back({arr[j].first, j});
				temp.push_back({arr[j].second, j});

				sort(temp.begin(), temp.end());

				if(temp[0].second != temp[1].second && temp[1].second != temp[2].second)
					tot++;
			}
		}

		for(int i=0; i<k; i++){
			int mi = min(arr[i].first, arr[i].second);
			int ma = max(arr[i].first, arr[i].second);


			// debug(ma, mi);
			int temp1 = 0;
			for(int i=mi; i<ma; i++)
				if(used[i] == 0)
					temp1++;


			int temp2 = 0;
			int steps = 2*n - (ma-mi);
			for(int i=ma, j=0; j<steps; j++){
				if(used[(i+j)%(2*n)] == 0)
					temp2++;
			}

			tot += min(temp1, temp2);

		}

		int remchords = n-k;
		tot += remchords*(remchords-1)/2;
		cout << tot << "\n";

	}
}
