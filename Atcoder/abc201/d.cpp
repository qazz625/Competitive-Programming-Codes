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

//1 for Taka
//-1 for aoki

int inf = 10000000;

vector<string> mat;
int n, m;

int solve(int x, int y, int turn){
	if(x == n-1 && y == m-1)
		return 0;

	int a, b;
	// if(turn == 0){
		a = -inf, b = -inf;
	// }
	// else
	// 	a = inf, b = inf;

	if(x != n-1){
		if(mat[x+1][y] == '+'){
			a = 1*turn+solve(x+1, y, 1^turn);
		}
		else{
			a = -1*turn+solve(x+1, y, 1^turn);
		}
	}

	if(y != m-1){
		if(mat[x][y+1] == '+'){
			b = 1*turn+solve(x, y+1, 1^turn);
		}
		else{
			b = -1*turn+solve(x, y+1, 1^turn);
		}
	}

	debug(x, y, turn, a, b);

	// if(turn == 0)/
		return max(a, b);
	// else
	// 	return min(a, b);
}

int32_t main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		mat.push_back(s);
	}

	int ans = solve(0, 0, 1);
	debug(ans);

	if(ans > 0){
		cout << "Takahashi\n";
	}
	else if(ans < 0){
		cout << "Aoki\n";
	}
	else{
		cout << "Draw\n";
	}
}

//Read the stuff at the top