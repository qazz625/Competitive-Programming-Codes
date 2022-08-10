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
		vector<int> arr(n);
		for(int i=0; i<n; i++)
			cin >> arr[i];

		int flag = 0;
		for(int i=0; i<(1<<n); i++){
			vector<int> elements;
			for(int j=0; j<n; j++){
				if(i&(1<<j))
					elements.push_back(arr[j]);
			}

			set<int> sums;
			for(int j=0; j<(1<<elements.size()); j++){
				int tot = 0;
				for(int k=0; k<elements.size(); k++){
					if(j&(1<<k))
						tot += elements[k];
					else
						tot += -elements[k];
				}
				sums.insert(tot);
			}

			for(int j=0; j<n; j++){
				if( (i&(1<<j)) == 0 && sums.find(arr[j]) != sums.end()){
					flag = 1;
				}
			}

		}
		if(flag == 1){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}


}
