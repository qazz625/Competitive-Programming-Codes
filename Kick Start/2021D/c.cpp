#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define int long long

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
 tree_order_statistics_node_update> 
    pbds_set; 
    
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

/* 
#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif
*/


int32_t main(){
	int t;
	cin >> t;
	for(int tt=0; tt<t; tt++){
		int n, m;
		cin >> n >> m;
		pbds_set pset;
		pset.insert({-1ll<<62, -1ll<<62});
		pset.insert({1ll<<62, 1ll<<62});

		for(int i=0; i<n; i++){
			int l, r;
			cin >> l >> r;
			pset.insert({l, r});
		}
		cout << "Case #" << tt+1 << ": ";
		for(int i=0; i<m; i++){
			int val;
			cin >> val;
			int s = 0, e = pset.size()-1, ans = -1;
			while(s <= e){
				int mid = (s+e)/2;
				pair<int, int> p = *pset.find_by_order(mid);
				if(p.first <= val){
					ans = mid;
					s = mid+1;
				}
				else{
					e = mid-1;
				}
			}

			pair<int, int> p1 = *pset.find_by_order(ans);
			pair<int, int> p2 = *pset.find_by_order(ans+1);

			int res;
			if(val > p1.second){
				if(val-p1.second <= p2.first-val){
					res = p1.second;
					pset.erase(pset.find(p1));
					if(p1.first != p1.second){
						p1.second--;
						pset.insert(p1);
					}
				}
				else{
					res = p2.first;
					pset.erase(pset.find(p2));
					if(p2.first != p2.second){
						p2.first++;
						pset.insert(p2);
					}
				}
			}

			else{
				res = val;
				pair<int, int> ins1 = {p1.first, val-1};
				pair<int, int> ins2 = {val+1, p1.second};
				pset.erase(pset.find(p1));
				if(ins1.first <= ins1.second)
					pset.insert(ins1);
				if(ins2.first <= ins2.second)
					pset.insert(ins2);
			}

			cout << res << " ";

		}
		cout << "\n";
	}


}
