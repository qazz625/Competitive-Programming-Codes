/*
THINGS TO DO
1) Check integer overflows
2) Check corner cases
3) Compile and run once on terminal
4) Code smart, not quick
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

typedef tree<int, null_type, less<int>, rb_tree_tag,
 tree_order_statistics_node_update> 
    pbds_set; 
    
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
   
#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n;

int solveeven(int evenr[], int oddl[], int evenl[], int oddr[], int ind){
	int ans1, ans2;
	{
		int s = ind, e = n-1, ans = 0;
		while(s <= e){
			int mid = (s+e)/2;
			int evennum = mid/2 - (ind-1)/2;
			if(ind == 0)
				evennum++;

			int curevenr;
			if(ind == 0)
				curevenr = evenr[mid];
			else
				curevenr = evenr[mid] - evenr[ind-1];
			// debug(ind, mid, curevenr, evennum);
			if(curevenr == evennum){
				ans = mid;
				s = mid+1;
			}
			else{
				e = mid-1;
			}
		}
		ans1 = ans;
	}

	{
		int s = ind, e = n-1, ans = 0;
		while(s <= e){
			int mid = (s+e)/2;
			int evennum = mid/2 - (ind-1)/2;
			if(ind == 0)
				evennum++;

			int oddnum = (mid-ind+1) - evennum;

			int curoddl;
			if(ind == 0)
				curoddl = oddl[mid];
			else
				curoddl = oddl[mid] - oddl[ind-1];
			debug(ind, mid, curoddl, oddnum);
			if(curoddl == oddnum){
				ans = mid;
				s = mid+1;
			}
			else{
				e = mid-1;
			}
		}
		ans2 = ans;
	}

	ans1 = min(ans1, ans2);
	debug(ans1);
	return ans1 - ind;
}




int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		string s;
		cin >> s;

		int evenl[n] = {0}, oddl[n] = {0}, evenr[n] = {0}, oddr[n] = {0};
		if(s[0] == 'L')
			evenl[0]++;
		if(s[0] == 'R')
			evenr[0]++;
		for(int i=2; i<n; i+=2){
			evenl[i] = evenl[i-2];
			evenr[i] = evenr[i-2];
			if(s[i] == 'L'){
				evenl[i]++;
				evenr[i] = 0;
			}
			else{
				evenr[i]++;
				evenl[i] = 0;
			}
		}

		if(s[1] == 'L')
			oddl[1]++;
		if(s[1] == 'R')
			oddr[1]++;
		for(int i=3; i<n; i+=2){
			oddl[i] = oddl[i-2];
			oddr[i] = oddr[i-2];
			if(s[i] == 'L'){
				oddl[i]++;
				oddr[i] = 0;
			}
			else{
				oddr[i]++;
				oddl[i] = 0;
			}
		}

		print(evenl, n);
		print(evenr, n);
		print(oddl, n);
		print(oddr, n);

		for(int i=0; i<n; i++){
			// solveeven(evenr, oddl, evenl, oddr, i);
			// else{
			// 	solveodd();
			// }
		}

	}


}

//Read the stuff at the top