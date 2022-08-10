#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int xorarr[1000000];

int32_t main(){

	for(int i=1; i<1000000; i++){
		xorarr[i] = xorarr[i-1]^i;
	}


	// print(xorarr, 10);

	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		int xorval = xorarr[a-1];
		// debug(xorval, xorval^b, a, b);
		if(xorval == b){
			cout << a << "\n";
		}
		else if((xorval^b) != a){
			cout << a+1 << "\n";
		}
		else{
			cout << a+2 << "\n";
		}
	}

}

//Read the stuff at the top