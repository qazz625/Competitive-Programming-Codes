#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

#define MAX 2010

void ask(int n){
	cout << "? " << n+1 << endl;
}

vector<vector<int>> queried(MAX);
int ans[MAX][MAX];

pair<int, int> checkedge(vector<int> &a, vector<int> &b){
	int sa[MAX] = {0}, sb[MAX] = {0};
	for(auto x: a)
		sa[x] = 1;
	for(auto x: b)
		sb[x] = 1;

	int minb = 100000, minindb = -1;
	int aq = -1;
	for(auto x: a){
		if(queried[x].size() != 0){
			aq = x;
			for(int i=0; i<queried[x].size(); i++){
				if(sb[i] != 0 && queried[x][i] < minb){
					minb = queried[x][i];
					minindb = i;
				}
			}
		}
	}

	int mina = 100000, mininda = -1;
	for(auto x: b){
		if(queried[x].size() != 0){
			for(int i=0; i<queried[x].size(); i++){
				if(sa[i] != 0 && queried[x][i] < mina){
					mina = queried[x][i];
					mininda = i;
				}
			}
		}
	}
	// debug(mininda, minindb);


	if(queried[aq][mininda]+1 == queried[aq][minindb]){
		return {mininda, minindb};
	}
	else{
		return {-1, -1};
	}

}

int32_t main(){
	int n;
	cin >> n;
	int done[n] = {0};

	int donecount = 0, qcount = 0;
	vector<vector<int>> components;
	for(int ii=0; ii<n; ii++){
		if(done[ii] == 1)
			continue;

		int fr = ii;
		ask(fr);

		vector<int> inp(n);
		vector<pair<int, int>> vp;
		for(int i=0; i<n; i++){
			cin >> inp[i];
			vp.push_back({inp[i], i});
		}

		queried[ii] = inp;

		sort(vp.begin(), vp.end());

		vector<int> temp;

		int ind = 0;
		while(ind != n-1 && vp[ind+1].first > vp[ind].first){
			pair<int, int> p = {vp[ind+1].second, vp[ind].second};
			if(p.first > p.second)
				swap(p.first, p.second);
			ans[p.first][p.second] = 1;
			if(done[vp[ind].second] == 0){
				done[vp[ind].second] = 1;
				temp.push_back(vp[ind].second);
				donecount++;
			}
			ind++;
		}

		int r = vp[ind-1].second;
		int val = vp[ind].first;

		while(ind != n && vp[ind].first == val){
			pair<int, int> p = {vp[ind].second, r};
			if(p.first > p.second)
				swap(p.first, p.second);
			ans[p.first][p.second] = 1;
			if(done[vp[ind].second] == 0){
				// q.push(vp[ind].second);
				done[vp[ind].second] = 1;
				temp.push_back(vp[ind].second);
				donecount++;
			}
			ind++;
		}
				// print(done, n);

		components.push_back(temp);
		if(donecount == n)
			break;
	}

	// print(components);

	// print(queried);
	// int belongsTo[n] = {0};
	// for(int i=0; i<components.size(); i++){
	// 	for(int)
	// }

	int mininds[components.size()][components.size()];

	for(int i=0; i<components.size(); i++){
		for(int j=i+1; j<components.size(); j++){
			pair<int, int> p = checkedge(components[i], components[j]);
			if(p.first > p.second)
				swap(p.first, p.second);
			if(p.first != -1)
				ans[p.first][p.second] = 1;
		}
	}

	cout << "!" << "\n"; 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(ans[i][j] == 1){
				cout << i+1 << " " << j+1 << "\n";
			}
		}
	}
	cout << endl;

}

