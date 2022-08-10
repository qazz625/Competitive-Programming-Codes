#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int k;

int solve(int arr[], int n){
	sort(arr, arr+k, greater<int>());
	int chosenind = -1;
	// print(arr, k);
	for(int i=0; i<k; i++){
		if(n > 1 && arr[i] > 1){
			n -= 2;
			arr[i] -= 2;
			chosenind = i;
		}
	}

	// print(arr, k);

	for(int i=0; i<=chosenind; i++){
		if(n > arr[i]){
			n -= arr[i];
		}
		else{
			return 1;
		}
	}

	return 0;
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m >> k;
		int arr[k];
		for(int i=0; i<k; i++)
			cin >> arr[i];

		int filledrows[k] = {0}, filledcols[k] = {0};
		for(int i=0; i<k; i++){
			filledrows[i] += arr[i]/m;
			filledcols[i] += arr[i]/n;
		}

		// int tot1 = 0, tot2 = 0;
		// for(int i=0; i<k; i++){
		// 	tot1 += filledrows[i];
		// 	tot2 += filledcols[i];
		// }
		// 		debug(tot1, tot2);

		int a = solve(filledrows, n);
		int b = solve(filledcols, m);


		if(a || b){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}

