#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

bool check(vector<int> &partialsort, vector<int> &arr){
	// print(partialsort);
	for(int i=0; i<arr.size()-3; i++){
		if(partialsort[i] != arr[i])
			return true;
	}
	return false;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr(n), oriarr(n);
		for(int i=0; i<n; i++)
			cin >> arr[i];

		print(arr);
		oriarr = arr;
		print(arr);
		print(oriarr);

		if(n == 2){
			if(arr[0] < arr[1]){
				cout << "0\n\n";
			}
			else{
				cout << "1\n1\n";
			}
			continue;
		}

		vector<int> result;


		vector<pair<int, int>> sorted;
		for(int i=0; i<n; i++)
			sorted.push_back({arr[i], i});
		// print(sorted);
		// print(arr);
		sort(sorted.begin(), sorted.end()); 

		int turn = 0;
		vector<int> minindices = {sorted[n-3].second, sorted[n-2].second, sorted[n-1].second};
		// print(sorted);
		sort(minindices.begin(), minindices.end());

		// print(minindices);

		// print(minindices);


		//push the three minimums to the end
		int endind = n-1;
		for(auto &ind: minindices){
			debug("CC");
			// debug(ind);
			if(endind == n-3)
				break;

			while(ind != endind){
				if(ind%2 == turn){
					swap(arr[ind], arr[ind+1]);
					result.push_back(ind);
					turn ^= 1;
					for(int i=0; i<3; i++){
						if(ind+1 == minindices[i]){
							minindices[i]--;
						}
					}
					ind++;
				}
				else{
					for(int i=0; i<endind-1; i++){
						if(i != ind && i+1 != ind && i%2){
							swap(arr[i], arr[i+1]);
							result.push_back(i);
							turn ^= 1;
							for(int j=0; j<3; j++){
								if(i+1 == minindices[j])
									minindices[j]--;
							}
							for(int j=0; j<3; j++){
								if(i == minindices[j])
									minindices[j]++;
							}
							break;
						}
					}
				}
			}
			endind--;
		}
		debug("BB");

		int ind = minindices[2];
		while(ind != endind){
			// debug(ind, endind, turn);
			if(ind%2 == turn){
				swap(arr[ind], arr[ind+1]);
				result.push_back(ind);
				turn ^= 1;
				ind++;
			}
			else{
				swap(arr[n-2], arr[n-1]);
				result.push_back(n-2);
				turn ^= 1;
			}
		}

		print(arr);
		debug("AA");

		// print(arr);

		// print(minindices);

		vector<int> partialsort;
		for(int i=1; i<=n-3; i++){
			partialsort.push_back(i);
		}

		print(partialsort);

		while(check(partialsort, arr)){
			int flag = 0;
			for(int i=0; i<n-4; i++){
				if(i%2 == turn && arr[i] > arr[i+1]){
					swap(arr[i], arr[i+1]);
					result.push_back(i);
					turn ^= 1;
					flag = 1;
					break;
				}
			}

			if(flag == 0){
				for(int i=n-3; i<n-1; i++){
					if(i%2 == turn){
						turn ^= 1;
						swap(arr[i], arr[i+1]);
						result.push_back(i);
						break;
					}
				}
			}
			// print(arr);
		}

		vector<int> final = {n-2, n-1, n};

		// print(result);

		while(arr[n-3] != n-2 || arr[n-2] != n-1 || arr[n-1] != n){
			for(int i=n-3; i<n-1; i++){
				if(i%2 == turn){
					swap(arr[i], arr[i+1]);
					turn ^= 1;
					result.push_back(i);
					break;
				}
			}
		}


		cout << result.size() << " " << n << "\n";
		print(oriarr);
		assert(result.size() <= n*n);
		for(int i=0; i<n; i++){
			assert(arr[i] == i+1);
		}
		// cout << result.size() << "\n";
		// for(auto x: result){
		// 	cout << x+1 << " ";
		// }
		// cout << "\n";

		// print(arr);


	}
}
