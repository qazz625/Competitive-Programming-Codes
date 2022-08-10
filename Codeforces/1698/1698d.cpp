#include <bits/stdc++.h>
using namespace std;

void solve(int l, int r){
	if(l == r){
		cout << "! " << l << endl;
		return;
	}

	int mid = (l+r)/2;

	cout << "? " << l << " " << mid << endl;
	int in = 0;
	for(int i=0; i<mid-l+1; i++){
		int x;
		cin >> x;
		if(l <= x && x <= mid)
			in++;
	}

	if(in%2)
		solve(l, mid);
	else
		solve(mid+1, r);
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		solve(1, n);
	}
}
