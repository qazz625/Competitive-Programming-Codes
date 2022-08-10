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
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		sort(arr, arr+n);

		int ans[n] = {0};

		int start = n/2;

		for(int i=0, j=start; j<n; j++, i+=2){
			ans[i] = arr[j];
		}

		// print(ans, n);

		start = 0;
		for(int i=-1, j=start; j<n/2; j++, i+=2){
			// debug(i, j, arr[j]);
			ans[(i+n)%n] = arr[j];
		}

		// print(ans, n);

		int flag = 0;
		for(int i=0; i<n; i++){
			int curval = ans[i];
			int nextval = ans[(i+1)%n];
			int prevval = ans[(i-1+n)%n];
			bool cond1 = curval > nextval && curval > prevval;
			bool cond2 = curval < nextval && curval < prevval;
			// debug(i, cond1, cond2);
			if((!cond1) && (!cond2))
				flag = 1;
		}

		if(flag == 1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
			for(int i=0; i<n; i++)
				cout << ans[i] << " ";
			cout << "\n";
		}


	}
}

