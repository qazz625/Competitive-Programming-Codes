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

pair<int, int> get_location(vector<pair<int, int>> &location, vector<vector<int>> &components, int permnum, int x){
	int comp = location[x].first;
	int si = components[comp].size();
	int index = (((-permnum)%si + si)%si + location[x].second)%si;
	return {comp, index};
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		int perm[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
			arr[i]--;
		}
		for(int i=0; i<n; i++){
			cin >> perm[i];
			perm[i]--;
		}

		vector<int> front(n), back(n);

		for(int i=0; i<n; i++){
			front[arr[i]] = perm[i];
			back[perm[i]] = front[i];
		}

		vector<vector<int>> components;

		//component number and offset of index
		vector<pair<int, int>> location(n);

		int done[n];

		for(int i=0; i<n; i++){
			if(done[i] == 1)
				continue;
			vector<int> temp;
			int ori = i;
			do{
				location[i].first = components.size();
				location[i].second = temp.size();
				temp.push_back(i);
				i = front[i];
				done[i] = 1;
			}
			while(i != ori);
			components.push_back(temp);
		}
		print(components);
		print(location);

		int permnum = 0;
		int q;
		cin >> q;
		while(q--){
			int type;
			cin >> type;
			if(type == 1){
				permnum++;
			}
			else if(type == 2){
				int x, y;
				cin >> x >> y;
				x--; y--;
				pair<int, int> locx = get_location(location, components, permnum, x);
				pair<int, int> locy = get_location(location, components, permnum, y);

				swap(location[x], location[y]);
				// swap(components[locx.first][locx.second], components[locy.first][locy.second]);
			}
			else{
				int x;
				cin >> x;
				x--;

				pair<int, int> temp = get_location(location, components, permnum, x);
				int comp = temp.first;
				int index = temp.second;
				
				cout << components[comp][index]+1 << "\n";
			}

			// print(components);
			// print(location);
		}


	}


}

//Read the stuff at the top