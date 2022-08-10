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

struct node{
	int value, prev, next, dummy;
	node(int a, int b, int c, int d){
		value = a;
		prev = b;
		next = c;
		dummy = d;
	}
};

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		string s;
		cin >> s;
		int n = s.size();

		if(count(s.begin(), s.end(), s[0]) == s.size()){

			continue;
		}


		vector<node> v;
		node df1(s[0], 1, -1, 1), df2(s[0], 2, 0, 1), df3(s[0], 3, 1, 1);
		node db1(s[n-1], n+4, n+2, 1), db2(s[n-1], n+5, n+3, 1), db3(s[n-1], -1, n+4, 1);


		v.push_back(df1);
		v.push_back(df2);
		v.push_back(df3);
		for(int i=3; i<n+3; i++){
			node cur(s[i-3], i+1, i-1, 0);
			v.push_back(cur);
		}
		v.push_back(db1);
		v.push_back(db2);
		v.push_back(db3);


		int cur = 0;
		while(cur < n+3){
			while(v[cur].dummy == 1)
				cur = v[cur].next;

			if(v[cur].value == v[v[cur].prev].value && v[cur].value == v[v[cur].next].value && v[cur].value == 'A'){
				a--;
				v[v[cur].prev].next = v[cur].next;
				v[v[cur].next].prev = v[cur].prev;
				cur = v[cur].prev;
				continue;
			}
			if(v[cur].value == v[v[cur].prev].value && v[cur].value == v[v[cur].next].value && v[cur].value == 'B'){
				a--;
				v[v[cur].prev].next = v[cur].next;
				v[v[cur].next].prev = v[cur].prev;
				cur = v[cur].prev;
				continue;
			}

		}






		// int start = 0, end = s.size()-1;
		// while(s[start] == s[start+1]){
		// 	if(s[start] == 'A')
		// 		a--;
		// 	else
		// 		b--;
		// 	start++;
		// }
		// while(s[end] == s[end-1]){
		// 	if(s[end] == 'A')
		// 		a--;
		// 	else
		// 		b--;
		// 	end--;
		// }

		// debug(a, b, c, d);


		// string news;
		// news += s[start];
		// for(int i=start+1; i<end; i++){
		// 	if(s[i] == s[i+1] && s[i] == s[i-1] && s[i] == 'A')
		// 		a--;
		// 	else if(s[i] == s[i+1] && s[i] == s[i-1] && s[i] == 'B')
		// 		b--;
		// 	else
		// 		news += s[i];
		// }
		// news += s[end];


		// int acount = count(news.begin(), news.end(), 'A');
		// int bcount = count(news.begin(), news.end(), 'B');

		// debug(acount);
		// if(a >= 0 && b >= 0 && acount == a+c+d && bcount == b+c+d){
		// 	cout << "YES\n";
		// }
		// else{
		// 	cout << "NO\n";
		// }

		// debug(a, b, c, d);
		// debug(news);


	}


}

//Read the stuff at the top