#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int check(multiset<int> &arr, int num){
	while(arr.size() != 0 && *arr.begin() <= num){
		num += *arr.begin();
		arr.erase(arr.begin());
	}

	if(arr.size() == 0)
		return 1;
	else
		return 0;
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n], oriarr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
			oriarr[i] = arr[i];
		}

		sort(arr, arr+n);

		int s = 0, e = n-1;
		int ans = -1;
		while(s <= e){
			int mid = (s+e)/2;
			multiset<int> temparr;
			for(int i=0; i<n; i++)
				if(i != mid)
					temparr.insert(arr[i]);

			int c = check(temparr, arr[mid]);
			if(c == 1){
				ans = mid;
				e = mid-1;
			}
			else{
				s = mid+1;
			}
		}

		cout << n-ans << "\n";
		for(int i=0; i<n; i++){
			if(oriarr[i] >= arr[ans])
				cout << i+1 << " ";
		}
		cout << "\n";
	}
}
