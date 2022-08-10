#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


int32_t main(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> zarr = z_function(s);
	// print(zarr);

	int ind = n;
	for(int i=1; i<n; i++){
		char one ='P', two='P';
		if(zarr[i] >= i)
			one = '~';
		else
			one = s[zarr[i]];

		if(zarr[i] >= n-i)
			two = '~';
		else
			two = s[i+zarr[i]];

		if(one < two){
			ind = i;
			break;
		}
	}
	for(int j=0; j<k; j++){
		cout << s[j%ind];
	}
	cout << "\n";


}

