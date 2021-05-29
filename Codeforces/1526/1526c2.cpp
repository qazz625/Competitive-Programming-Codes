#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n;

int solve(multiset<int> &ms, int arr[]){
	int cur = 0;
	int orisize = ms.size();
	// debug("AA");
	for(int i=0; i<n; i++){
		// debug(i, cur);
		if(arr[i] >= 0){
			cur += arr[i];
		}
		else{
			if(ms.find(arr[i]) != ms.end() && cur+arr[i] >= 0){
				cur += arr[i];
				ms.erase(ms.find(arr[i]));
			}
			else{
				//do nothing
			}
		}
		// print(ms);
	}
	return orisize-ms.size();
}


int32_t main(){
	cin >> n;
	int arr[n];
	vector<int> neg;
	int pos = 0;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		if(arr[i] < 0)
			neg.push_back(arr[i]);
		else
			pos++;
	}

	sort(neg.begin(), neg.end(), greater<int>());
	// print(neg);


	int s = 0, e = neg.size()-1, ans = -1;
	while(s <= e){
		int mid1 = s + (e-s)/3;
		int mid2 = e - (e-s)/3;

		multiset<int> ms1;
		for(int i=0; i<=mid1; i++){
			ms1.insert(neg[i]);
		}

		multiset<int> ms2;
		for(int i=0; i<=mid2; i++){
			ms2.insert(neg[i]);
		}

		// print(ms1);
		// print(ms2);

		int consumed1 = solve(ms1, arr);
		int consumed2 = solve(ms2, arr);

		// debug(consumed1, consumed2, mid1, mid2);

		if(consumed1 >= consumed2){
			ans = consumed1;
			e = mid2-1;
		}
		if(consumed1 <= consumed2){
			ans = consumed2;
			s = mid1+1;
		}

	}

	cout << pos + ans << "\n";


}

