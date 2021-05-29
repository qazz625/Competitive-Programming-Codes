/*
THINGS TO DO
1) Check integer overflows
2) Check corner cases
3) Compile and run once on terminal
4) Code smart, not quick
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

void ask(int l, int r){
	cout << "? " << l << " " << r << endl;
}


int32_t main(){
	int n;
	cin >> n;

	ask(1, n);
	int smax;
	cin >> smax;

	int s = 1, e = n;
	int ans = -1;
	while(s < e){
		int mid = (s+e)/2;
		if((s+e)%2 == 1)
			mid++;

		ask(1, mid);
		int in;
		cin >> in;
		if(in == smax){
			ans = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}

	debug(ans);



}

//Read the stuff at the top