#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		int indegree[n] = {0};

		for(int i=0; i<n; i++){
			cin >> arr[i];
			arr[i]--;
			indegree[arr[i]]++;
		}

		int visited[n] = {0};
		for(int i=0; i<n; i++)
			if(indegree[i] == 0)
				visited[i] = 2;


		vector<int> ans(n, -1);
		vector<int> unhappy, useless;
		for(int i=0; i<n; i++){
			if(visited[i] == 1 || visited[i] == 0)
				continue;

			int cur = i;
			visited[cur] = 1;
			while(visited[arr[cur]] != 1){
				ans[cur] = arr[cur];
				cur = arr[cur];
				visited[cur] = 1;
			}
			if(cur != i){
				ans[cur] = i;
				if(arr[cur] != i)
					unhappy.push_back(cur);
			}
			else{
				useless.push_back(i);
			}
		}


		for(int i=0; i<n; i++){
			if(visited[i] == 0){
				int cur = i;
				visited[cur] = 1;
				while(visited[arr[cur]] == 0){
					ans[cur] = arr[cur];
					cur = arr[cur];
					visited[cur] = 1;
				}
			}
		}


		// print(unhappy);
		// print(useless);
		// print(ans);

		if(useless.size() == 1){
			assert(unhappy.size() != 0);
			ans[useless[0]] = ans[unhappy[0]];
			ans[unhappy[0]] = useless[0];
		}
		else if(useless.size() > 1){
			for(int i=0; i<(int)useless.size()-1; i++){
				ans[useless[i]] = useless[i+1];
			}
			ans[useless.back()] = useless[0];
		}


		int ansval = 0;
		for(int i=0; i<n; i++)
			if(arr[i] == ans[i])
				ansval++;

		cout << ansval << "\n";

		for(int i=0; i<n; i++)
			cout << ans[i]+1 << " ";
		cout << "\n";

	}


}
