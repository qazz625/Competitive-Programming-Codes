#include <bits/stdc++.h>
using namespace std;

int n, m;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		string graph[n];
		for(int i=0; i<n; i++){
			cin >> graph[i];
		}

		pair<int, int> ind = {-1, -1};

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(i != j && graph[i][j] == graph[j][i])
					ind = {i, j};


		if(ind.first != -1){
			cout << "YES\n";
			for(int i=0; i<=m; i++){
				if(i%2 == 0)
					cout << ind.first+1 << " ";
				else
					cout << ind.second+1 << " ";
			}
			cout << "\n";
			continue;
		}

		int flag = -1;
		for(int i=0; i<n; i++){
			if(graph[i].find('a') != graph[i].npos && graph[i].find('b') != graph[i].npos){
				flag = i;
			}
		}

		if(flag == -1){
			if(m%2 == 0)
				cout << "NO";
			else{
				cout << "YES\n";
				for(int i=0; i<=m; i++)
					cout << i%2 + 1 << " ";
			}
			cout << "\n";
		}
		else{
			int ind2, ind3;
			for(int i=0; i<n; i++){
				if(graph[flag][i] == 'a'){
					ind2 = i;
				}
				else if(graph[flag][i] == 'b'){
					ind3 = i;
				}
			}

			vector<int> ans(m+1, -1);
			if(m%4 == 2){
				for(int i=0; i<=(m+1)/2; i+=2){
					ans[i] = ind2;
					ans[i+1] = flag;
				}
				for(int i=(m+1)/2+1; i<(m+1); i+=2){
					ans[i] = ind3;
					ans[i+1] = flag;
				}
			}

			else if(m%4 == 0){
				for(int i=0; i<=(m+1)/2; i+=2){
					ans[i] = flag;
					ans[i+1] = ind2;
				}
				for(int i=(m+1)/2+1; i<(m+1); i+=2){
					ans[i] = ind3;
					ans[i+1] = flag;
				}
			}

			else{
				int vert = flag;
				char lookfor = 'a';
				ans[0] = flag;
				for(int i=1; i<=m; i++){
					for(int j=0; j<n; j++){
						if(graph[vert][j] == lookfor){
							ans[i] = j;
							vert = j;
							if(lookfor == 'a')
								lookfor = 'b';
							else
								lookfor = 'a';
							break;
						}
					}
				}
			}

			cout << "YES\n";
			for(int i=0; i<=m; i++)
				cout << ans[i]+1 << " ";
			cout << "\n";
		}
}
}
