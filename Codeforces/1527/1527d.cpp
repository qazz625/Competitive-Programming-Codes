#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


void dfs(vector<int> tree[], int v, int p, vector<int> &in, vector<int> &out,
	vector<int> &euler, vector<int> &subtree){
	in[v] = euler.size();
	euler.push_back(v);
	subtree[v] = 1;
	for(auto x: tree[v]){
		if(x != p){
			dfs(tree, x, v, in, out, euler, subtree);
			subtree[v] += subtree[x];
		}
	}
	out[v] = euler.size();
	euler.push_back(v);
}


//a inside b
int inside(int a, int b, vector<int> &in, vector<int> &out){

	if(in[a] >= in[b] && out[a] <= out[b])
		return 1;
	return 0;
}



int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> tree[n];
		for(int i=0; i<n-1; i++){
			int u, v;
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		vector<int> in(n), out(n), euler;
		vector<int> subtree(n);
		dfs(tree, 0, -1, in, out, euler, subtree);

		// print(subtree);
		// print(euler);

		vector<int> chain = {0};

		vector<int> ans(n+1);
		int onesubtree = -1;
		for(auto x: tree[0]){
			ans[0] += subtree[x]*(subtree[x]-1)/2;
			if(in[1] >= in[x] && out[1] <= out[x]){
				onesubtree = x;
			}
		}

		// print(ans);
		// debug(onesubtree);

		int one = 1, two = subtree[onesubtree];
		vector<int> temp;
		for(auto x: tree[0]){
			if(x != onesubtree)
				temp.push_back(subtree[x]);
			else{
				temp.push_back(subtree[x] - subtree[onesubtree]);
				if(temp.back() == 0)
					temp.pop_back();
			}
		}


		// print(temp);

		int o = 0, t = 0;
		for(int i=0; i<temp.size(); i++){
			o += temp[i];
			t += temp[i]*temp[i];
		}

		// debug(o, t);


		if(temp.size() <= 1){
			ans[1] = o;
		}
		else{
			ans[1] = (t-o)/2 + o + 1;
		}



		// debug(one, two);

		// ans[1] = one*two;
		// print(ans);


		int zerost = 1;
		for(auto x: tree[0]){
			if(inside(onesubtree, x, in, out))
				continue;
			zerost += subtree[x];
		}

		int flag = 0, i = 2;
		int branch1 = 1, branch2 = -1;
		// debug(zerost, subtree[branch1]);

		for(; i<n; i++){
			//if correct order
			if(inside(i, branch1, in, out)){
				ans[i] = zerost*(subtree[branch1]-subtree[i]);
				branch1 = i;
			}
			//incorrect ordering
			else if(inside(branch1, i, in, out)){
				flag = 1;
				break;
			}
			else{
				// debug("BB");
				branch2 = i;
				for(auto x: tree[0]){
					if(inside(branch1, x, in, out) && inside(branch2, x, in, out))
						flag = 1;
				}
				if(flag == 0){
					ans[i] = (zerost-subtree[i])*subtree[branch1];
				}
				else{
					ans[i] = zerost*subtree[branch1];
				}
				i++;
				break;
			}
		}
		// debug(flag);

		

		if(flag == 1){
			for(; i<n; i++)
				ans[i] = 0;
		}

		if(i == n){
			if(flag == 0){
				ans[n] = 1;
			}

			for(int i=0; i<=n; i++){
				cout << ans[i] << " ";
			}
			cout << "\n";
			continue;
		}


		// print(ans);

		for(; i<n; i++){
			if(inside(i, branch1, in, out)){
				ans[i] = subtree[branch2] * (subtree[branch1] - subtree[i]);
				branch1 = i;
			}
			else if(inside(i, branch2, in, out)){
				ans[i] = subtree[branch1] * (subtree[branch2] - subtree[i]);
				branch2 = i;
			}
			else{
				ans[i] = subtree[branch2]*subtree[branch1];
				flag = 1;
				break;
			}
		}

		if(flag == 0){
			ans[n] = 1;
		}
		else{
			for(; i<=n; i++){
				ans[i] = 0;
			}
		}

		for(int i=0; i<=n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";


	}


}

