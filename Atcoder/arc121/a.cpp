#include <bits/stdc++.h>
using namespace std;

#define int long long


#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int inf = 1ll<<60;


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr[3];

	for(int i=0; i<2*n; i++){
		char colour;
		int val;
		cin >> val >> colour;

		if(colour == 'R')
			arr[0].push_back(val);
		if(colour == 'G')
			arr[1].push_back(val);
		if(colour == 'B')
			arr[2].push_back(val);
	}


	vector<int> oddind;
	int evenind = -1;
	for(int i=0; i<3; i++){
		sort(arr[i].begin(), arr[i].end());
		if(arr[i].size()%2 == 1)
			oddind.push_back(i);
		else
			evenind = i;
	}

	// print(oddind);


	if(oddind.size() == 0){
		cout << "0\n";
		return 0;
	}

	int ans = inf;

	//both odd
	int ind1 = oddind[0], ind2 = oddind[1];
	for(auto x: arr[ind1]){
		auto itr = lower_bound(arr[ind2].begin(), arr[ind2].end(), x);
		int one = inf, two = inf;
		if(itr != arr[ind2].end()){
			one = *itr;
		}
		if(itr != arr[ind2].begin()){
			// debug("AA");
			itr--;
			two = *itr;
		}
		ans = min({ans, abs(one-x), abs(two-x)});
	}

	// print(arr[evenind]);


	//one even one odd
	int ans1 = inf;
	for(auto x: arr[ind1]){
		auto itr = lower_bound(arr[evenind].begin(), arr[evenind].end(), x);
		int one = inf, two = inf;
		if(itr != arr[evenind].end()){
			one = *itr;
		}
		if(arr[evenind].size() != 0 && itr != arr[evenind].begin()){
			itr--;
			two = *itr;
		}
		// debug(x, one, two);
		ans1 = min({ans1, abs(one-x), abs(two-x)});
	}


	int ans2 = inf;
	for(auto x: arr[ind2]){
		auto itr = lower_bound(arr[evenind].begin(), arr[evenind].end(), x);
		int one = inf, two = inf;
		if(itr != arr[evenind].end()){
			one = *itr;
		}
		if(arr[evenind].size() != 0 && itr != arr[evenind].begin()){
			itr--;
			two = *itr;
		}
		ans2 = min({ans2, abs(one-x), abs(two-x)});
	}
	// debug(ans, ans1, ans2);


	cout << min(ans, ans1+ans2) << "\n";

}
