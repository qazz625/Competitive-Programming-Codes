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
		vector<int> arr(n);

		for(int i=0; i<n; i++)
			cin >> arr[i];

		multiset<int> evenpos, oddpos;

		evenpos.insert(arr[0]);
		oddpos.insert(arr[1]);

		int ans = n*arr[0] + n*arr[1];
		int evensum = arr[0], oddsum = arr[1];

		for(int i=2; i<n; i++){

			if(i%2 == 0){
				evenpos.insert(arr[i]);
				evensum += arr[i];
			}
			else{
				oddpos.insert(arr[i]);
				oddsum += arr[i];
			}

			int a = *evenpos.begin();
			int b = *oddpos.begin();

			int valeven = evensum-a + (n-(evenpos.size()-1))*a;
			int valodd = oddsum-b + (n-(oddpos.size()-1))*b;
			ans = min(ans, valeven+valodd);
		}
		cout << ans << "\n";
	}
}

