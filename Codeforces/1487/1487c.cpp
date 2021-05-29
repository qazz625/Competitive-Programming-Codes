#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			arr[i] = i;

		int score = n*(n-1)/2 / n;

		int graph[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				graph[i][j] = 0;
		}

		for(int i=0; i<n; i++){
			for(int j=1; j<=score; j++){
				graph[i][(i+j)%n] = 1;
				graph[(i+j)%n][i] = -1;
			}
		}

		int tie = 0;
		vector<int> ans;	
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				ans.push_back(graph[i][j]);
			}
		}
		for(int i=0; i<ans.size(); i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
}