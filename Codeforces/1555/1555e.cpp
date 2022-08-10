#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

struct interval{
	int l, r, w;
};

bool comp(interval &a, interval &b){
	return a.w < b.w;
}

bool setcomp(interval &a, interval &b){
	return a.l < b.l || (a.l == b.l && a.r < b.r);
}

int32_t main(){
	int n, m;
	cin >> n >> m;
	vector<interval> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i].l >> arr[i].r >> arr[i].w;
	}

	sort(arr.begin(), arr.end(), comp);

	for(int i=0; i<n; i++){
		cout << arr[i].l << " " << arr[i].r << " " << arr[i].w << "\n";
	}

	multiset<interval, decltype(setcomp)*> s(setcomp);
	s.insert(arr[0]);

	int maxreachable = arr[0].r;
	int ptr1 = 0, ptr2 = 0;

	while(ptr1 != n){
		if(ptr2 == n-1 || maxreachable == m){
			//remove
		}
		else{
			//add
			ptr2++;
			s.insert(arr[ptr2]);
			auto p = s.find(arr[ptr2]);
			if(p == s.begin()){
				if(maxreachable >= arr[ptr2].l){
					maxreachable = max(maxreachable)
				}
			}
			else if(p == --s.end()){

			}
			else{

			}
		}
	}



}

//Read the stuff at the top