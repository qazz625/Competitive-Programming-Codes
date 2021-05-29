#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n;

void construct(int arr[], int s, int e, int ans[], int depth){
	int ma = -1, ind = -1;
	for(int i=s; i<=e; i++){
		if(arr[i] > ma){
			ma = arr[i];
			ind = i;
		}
	}
	ans[ind] = depth;

	if(s <= ind-1)
		construct(arr, s, ind-1, ans, depth+1);
	if(ind+1 <= e)
		construct(arr, ind+1, e, ans, depth+1);
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];
		int ans[n] = {0};
		construct(arr, 0, n-1, ans, 0);
		
		for(int i=0; i<n; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
}
