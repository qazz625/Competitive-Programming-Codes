#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

//0 for left
//1 for right
int n, m;

void solve(vector<vector<int>> &even, vector<int> &ans){
	vector<vector<int>> left;
	for(int i=0; i<even.size(); i++){
		if(even[i][1] == 1){
			left.push_back(even[i]);
		}
		else{
			if(left.size() == 0)
				left.push_back(even[i]);
			else{
				vector<int> temp = left.back();
				left.pop_back();
				int loc1 = temp[0], loc2 = even[i][0];
				if(temp[1] == 1){
					ans[even[i][2]] = (loc2-loc1)/2;
					ans[temp[2]] = (loc2-loc1)/2;
				}
				else{
					ans[even[i][2]] = (loc2+loc1)/2;
					ans[temp[2]] = (loc2+loc1)/2;
				}
				
			}
		}
	}
	// debug("AA");
	// print(left);
	int ind1 = 0;
	for(; ind1+1 < left.size() && left[ind1][1]==0 && left[ind1+1][1] == 0; ind1+=2){
		int loc1 = left[ind1][0];
		int loc2 = left[ind1+1][0];
		ans[left[ind1][2]] = (loc2+loc1)/2;
		ans[left[ind1+1][2]] = (loc2+loc1)/2;
	}

	int ind2 = left.size()-1;
	for(; ind2 > 0 && left[ind2][1]==1 && left[ind2-1][1] == 1; ind2-=2){
		int loc1 = m-left[ind2][0];
		int loc2 = m-left[ind2-1][0];
		ans[left[ind2][2]] = (loc2+loc1)/2;
		ans[left[ind2-1][2]] = (loc2+loc1)/2;
	}

	// debug(ind1, ind2);
	if(ind1 == ind2){
		ans[left[ind1][2]] = -1;
	}
	else if(ind1 < ind2){
		int loc1 = left[ind1][0];
		int loc2 = m-left[ind2][0];
		ans[left[ind1][2]] = (loc2+loc1+m)/2;
		ans[left[ind2][2]] = (loc2+loc1+m)/2;
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		vector<vector<int>> even, odd;
		int arr[n];
		int dir[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		for(int i=0; i<n; i++){
			char c;
			cin >> c;
			if(c == 'L')
				dir[i] = 0;
			else
				dir[i] = 1;
		}

		for(int i=0; i<n; i++){
			if(arr[i]%2 == 0){
				even.push_back({arr[i], dir[i], i});
			}
			else{
				odd.push_back({arr[i], dir[i], i});
			}
		}

		vector<int> ans(n);

		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());

		// print(even);
		// print(odd);

		vector<vector<int>> left;

		solve(even, ans);
		solve(odd, ans);

		for(auto x: ans){
			cout << x << " ";
		}
		cout << "\n";
	}
}
