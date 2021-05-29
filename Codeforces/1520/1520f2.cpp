#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

void ask(int a, int b){
	cout << "? " << a << " " << b << endl;
}

vector<int> buildSegTree(vector<int> blocks){
	while((1<<30) % blocks.size() != 0)
		blocks.push_back(0);


	vector<int> segtree(2*blocks.size());

	for(int i=0; i<blocks.size(); i++){
		segtree[i+blocks.size()] = blocks[i];
	}

	for(int i=segtree.size()-1; i!=1; i-=2){
		segtree[i/2] = segtree[i] + segtree[i-1];
	}
	return segtree;
}

void update(vector<int> &segtree, int ind){
	ind += segtree.size()/2;
	while(ind != 0){
		segtree[ind] -= 1;
		ind /= 2;
	}
}

pair<int, int> query(vector<int> &segtree, int l, int r, int k, int ind, int cursum){
	if(l == r){
		return {ind, cursum};
	}
	else{
		int mid = (l+r)/2;
		// debug(segtree[2*ind], segtree[2*ind+1], ind, l, r, mid, cursum);
		if(segtree[2*ind] + cursum < k){
			//go right
			cursum += segtree[2*ind];
			return query(segtree, mid+1, r, k, 2*ind+1, cursum);
		}
		else{
			//go left
			return query(segtree, l, mid, k, 2*ind, cursum);
		}
	}
}

int blocksize = 10;

int32_t main(){
	int n, t;
	cin >> n >> t;
	vector<int> blocks;
	int num, flag = 0;
	int task = 2;

	vector<int> segtree;

	while(t--){
		int k;
		cin >> k;

		if(flag == 0 && task == 2){
			int i;
			for(i=0; i+blocksize<n; i+=blocksize){
				ask(i+1,i+blocksize);
				cin >> num;
				blocks.push_back(blocksize-num);
			}

			ask(i+1, min(n, i+blocksize));
			cin >> num;
			int lol = min(n, i+blocksize)-(i+1)+1-num;
			blocks.push_back(lol);
			flag = 1;

			segtree = buildSegTree(blocks);
			// print(segtree);
		}

		int ind, cursum;
		if(task == 2){
			pair<int, int> res = query(segtree, 0, segtree.size()/2-1, k, 1, 0);
			ind = res.first - segtree.size()/2;
			cursum = res.second;
			k -= cursum;
		}
		
		// debug(k, ind, cursum);

		// block index obtained now binary search
		int s, e, ans, start;
		if(task == 2){
			s = ind*blocksize, e = min(n-1, s+blocksize-1), ans = -1;
			start = ind*blocksize;
		}
		else{
			s = 0, e = n-1, ans = -1, start = 0;
		}
		
		// debug(s, e, start);
		// print(blocks);
		while(s <= e){
			int mid = (s+e)/2;
			ask(start+1, mid+1);
			cin >> num;
			int zeroes = mid-start+1 - num;
			// debug(zeroes, mid, start);
			if(zeroes >= k){
				ans = mid;
				e = mid-1;
			}
			else{
				s = mid+1;
			}
		}

		assert(ans != -1);


		cout << "! " << ans+1 << endl;
		if(task == 2)
			update(segtree, ind);

		// print(segtree);
	}
}
