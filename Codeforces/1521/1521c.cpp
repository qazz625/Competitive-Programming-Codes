#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


void ask(int t, int i, int j, int x){
	cout << "? " << t << " " << i+1 << " " << j+1 << " " << x << endl;
}

int one_index;

void check(int inp, int i, int j){
	if(inp == 1){
		one_index = i;
		return;
	}
	ask(1, i, i+1, 1);
	int in;
	cin >> in;

	if(in == 1){
		one_index = j;
	}

}

/*
t=1 max(min(x,pi),min(x+1,pj))
t=2 min(max(x,pi),max(x+1,pj))

*/

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, inp;
		one_index = -1;
		cin >> n;
		for(int i=0; i<n-1; i+=2){
			ask(2, i, i+1, 1);
			cin >> inp;
			if(inp <= 2){
				check(inp, i, i+1);
			}
		}
		if(n%2 == 1){
			ask(2, n-2, n-1, 1);
			cin >> inp;
			if(inp <= 2){
				check(inp, n-2, n-1);
			}
		}
		// debug(one_index);

		int arr[n];
		arr[one_index] = 1;
		for(int i=0; i<n; i++){
			if(i != one_index){
				ask(1, one_index, i, n-1);
				cin >> inp;
				arr[i] = inp;
			}
		}

		cout << "! ";
		for(int i=0; i<n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}


}