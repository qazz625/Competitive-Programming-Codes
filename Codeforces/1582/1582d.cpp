#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		int ans[n] = {0};
		for(int i=0; i+3<n; i+=2){
			int g = __gcd(arr[i], arr[i+1]);
			int goal = arr[i]*arr[i+1]/g;

			ans[i] = goal/arr[i];
			ans[i+1] = goal/arr[i+1]; 
			if(arr[i]*ans[i] < 0 && arr[i+1]*ans[i+1] < 0)
				ans[i] *= -1;
			else if(arr[i]*ans[i] > 0 && arr[i+1]*ans[i+1] > 0)
				ans[i] *= -1;
		}

		if(n%2 == 0){
			int g = __gcd(arr[n-2], arr[n-1]);
			int goal = arr[n-2]*arr[n-1]/g;

			ans[n-2] = goal/arr[n-2];
			ans[n-1] = goal/arr[n-1]; 

			if(arr[n-2]*ans[n-2] < 0 && arr[n-1]*ans[n-1] < 0)
				ans[n-2] *= -1;
			else if(arr[n-2]*ans[n-2] > 0 && arr[n-1]*ans[n-1] > 0)
				ans[n-2] *= -1;
		}
		else{
			int first, second, ind1, ind2, ind3;
			if(arr[n-3] + arr[n-2] != 0){
				first = arr[n-3] + arr[n-2];
				second = arr[n-1];
				ind1 = n-3; ind2 = n-2; ind3 = n-1;
			}
			else if(arr[n-2] + arr[n-1] != 0){
				first = arr[n-2] + arr[n-1];
				second = arr[n-3];
				ind1 = n-2; ind2 = n-1; ind3 = n-3;
			}
			else{
				first = arr[n-3] + arr[n-1];
				second = arr[n-2];
				ind1 = n-3; ind2 = n-1; ind3 = n-2;
			}
			// debug(first, second, ind1, ind2, ind3);

			int g = __gcd(first, second);
			int goal = first*second/g;

			ans[ind1] = goal/first;
			ans[ind2] = goal/first;
			ans[ind3] = goal/second;

			if(first*ans[ind2] > 0 && second*ans[ind3] > 0)
				ans[ind3] *= -1;
			else if(first*ans[ind2] < 0 && second*ans[ind3] < 0)
				ans[ind3] *= -1;
		}

		for(int i=0; i<n; i++){
			// assert(ans[i] <= 1000000000);
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}

