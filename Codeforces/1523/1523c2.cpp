#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;

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
		vector<int> v;

		for(int i=0; i<n; i++){
			int num;
			cin >> num;
			if(num == 1)
				v.push_back(1);
			else{
				while(v.back() != num-1)
					v.pop_back();
				v.pop_back();
				v.push_back(num);
			}

			for(int i=0; i<v.size()-1; i++){
				cout << v[i] << ".";
			}
			cout << v.back();
			cout << "\n";
		}
	}


}

//Read the stuff at the top