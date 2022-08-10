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
		int a[n], b[n];
		for(int i=0; i<n; i++)
			cin >> a[i];
		for(int i=0; i<n; i++)
			cin >> b[i];

		sort(a, a+n);
		sort(b, b+n);

		int flag = 0;
		for(int i=n-1; i>=0; i--){
			if(a[i] == b[i] || a[i]+1 == b[i]){

			}
			else{
				flag = 1;
			}
		}

		if(flag == 1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
}
