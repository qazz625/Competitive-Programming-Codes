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

#define MAX 62

double dp[MAX][MAX][MAX];
string answer[MAX][MAX][MAX];
double eps = 0.0001;

void solve(int w, int e, int r, int p, int s, int tot){
	// cout << r << " " << p << " " << s << " " << tot << "\n";
	if(tot == 1){
		dp[r][p][s] = (double)1/3*w + (double)1/3*e;
		if(r == 1)
			answer[r][p][s] = "R";
		else if(p == 1)
			answer[r][p][s] = "P";
		else
			answer[r][p][s] = "S";
		return;
	}

	double a = -1, b = -1, c = -1;
	if(r != 0 && abs(dp[r-1][p][s]) <= eps){
		solve(w, e, r-1, p, s, tot-1);
		a = dp[r-1][p][s];
	}
	if(p != 0 && abs(dp[r][p-1][s]) <= eps){
		solve(w, e, r, p-1, s, tot-1);
		b = dp[r][p-1][s];
	}
	if(s != 0 && abs(dp[r][p][s-1]) <= eps){
		solve(w, e, r, p, s-1, tot-1);
		c = dp[r][p][s-1];
	}

	if(a > b && a > c){
		dp[r][p][s] = a + (double)(r-1)/(tot-1)*e + (double)(s)/(tot-1)*w;
		answer[r][p][s] = answer[r-1][p][s] + 'R';
	}
	else if(b > a && b > c){
		dp[r][p][s] = b + (double)(p-1)/(tot-1)*e + (double)(r)/(tot-1)*w;
		answer[r][p][s] = answer[r][p-1][s] + 'P';
	}
	else{
		dp[r][p][s] = c + (double)(s-1)/(tot-1)*e + (double)(p)/(tot-1)*w;
		answer[r][p][s] = answer[r][p][s-1] + 'S';
	}
}

int32_t main(){
	int t;
	cin >> t;
	for(int tt=1; tt<=t; tt++){
		int w, e;
		cin >> w >> e;

		for(int i=0; i<MAX; i++){
			for(int j=0; j<MAX; j++){
				for(int k=0; k<MAX; k++){
					dp[i][j][k] = 0;
					answer[i][j][k] = "";
				}
			}
		}

		string ans;
		double ma = 0;
		for(int i=0; i<MAX; i++){
			for(int j=0; j<MAX; j++){
				for(int k=0; k<MAX; k++){
					if(i+j+k != 0 && i+j+k < MAX && dp[i][j][k] == 0){
						solve(w, e, i, j, k, i+j+k);
						if(i+j+k == 60 && dp[i][j][k] > ma){
							ma = dp[i][j][k];
							ans = answer[i][j][k];
						}
					}
				}
			}
		}

		cout << "Case #" << tt << ": " << ans << "\n";
	}

}

//Read the stuff at the top