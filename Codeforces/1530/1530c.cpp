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
		int n;
		cin >> n;
		int a[n], b[n];
		for(int i=0; i<n; i++)
			cin >> a[i];
		for(int i=0; i<n; i++)
			cin >> b[i];

		sort(a, a+n, greater<int>());
		sort(b, b+n, greater<int>());

		int num = n-n/4;

		int prefa[n], prefb[n];
		prefa[0] = a[0], prefb[0] = b[0];

		for(int i=1; i<n; i++){
			prefa[i] = prefa[i-1] + a[i];
			prefb[i] = prefb[i-1] + b[i];
		}

		if(prefa[num-1] >= prefb[num-1]){
			cout << "0\n";
			continue;
		}

		// print(a, n);
		// print(b, n);
		// print(prefa, n);
		// print(prefb, n);

		int s = 1, e = 1<<30, ans = -1;
		while(s <= e){
			int mid = (s+e)/2;
			int rounds = n + mid;
			int num = rounds - rounds/4;


			int scoreb = 0;
			if(num >= n){
				scoreb = prefb[n-1];
			}
			else{
				scoreb = prefb[num-1];
			}


			int scorea = 0;
			if(mid >= num){
				scorea = rounds*100;
			}
			else{
				scorea = mid*100;
				num -= mid;
				scorea += prefa[num-1];
			}

			if(scorea >= scoreb){
				ans = mid;
				e = mid-1;
			}
			else{
				s = mid+1;
			}

		}


		cout << ans << "\n";


	}
}