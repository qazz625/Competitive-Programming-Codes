#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n;

int check(int howMany, vector<pair<int, int>> arr){
	//how many more to buy to reach b
	int cost = 2*howMany;
	int cur = howMany;
	for(int i=n-1; i>=0; i--){
		if(arr[i].first <= howMany){
			howMany -= arr[i].first;
			arr[i].first = 0;
		}
		else{
			arr[i].first -= howMany;
			howMany = 0;
		}
	}

	// debug(cur, cost, howMany);
	// print(arr);
	for(int i=0; i<n; i++){
		if(arr[i].first != 0){
			if(cur < arr[i].second){
				cost += arr[i].second-cur;
				cur = arr[i].second;
				cost += arr[i].first;
			}
			else{
				cur += arr[i].first;
				cost += arr[i].first;
			}
		}
	}

	return cost;
}

bool compare(pair<int, int> p1, pair<int, int> p2){
	return make_pair(p1.second, p1.first) < make_pair(p2.second, p2.first);
}

int32_t main(){
	cin >> n;
	vector<pair<int, int>> arr(n);
	int e = 0;
	int s = 1ll<<60;
	for(int i=0; i<n; i++){
		cin >> arr[i].first >> arr[i].second;
		e += arr[i].first;
		s = min(s, arr[i].second);
	}

	sort(arr.begin(), arr.end(), compare);
	// print(arr);
	debug(s, e);

	int ans = -1;
	while(s <= e){
		int offset = (e-s)/3;

		int mid1 = s + offset;
		int mid2 = e - offset;
		int c1 = check(mid1, arr);
		int c2 = check(mid2, arr);
		// debug(mid1, mid2, c1, c2);

		if(c1 >= c2){
			s = mid1+1;
			ans = c2;
		}
		else{
			e = mid2-1;
			ans = c1;
		}
	}
	cout << ans << "\n";

}

