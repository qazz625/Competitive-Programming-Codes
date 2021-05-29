#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int arr[n];
		int goal[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		//0 yet to paint
		//1 already painted
		set<int> repaint[n+10][2];
		set<int> goalnums;
		for(int i=0; i<n; i++){
			cin >> goal[i];
			goalnums.insert(goal[i]);
			if(arr[i] != goal[i]){
				repaint[goal[i]][0].insert(i);
			}
			else{
				repaint[goal[i]][1].insert(i);
			}
		}

		vector<int> painters(m);
		for(int i=0; i<m; i++){
			cin >> painters[i];
		}

		int suffarr[m]={0};
		for(int i=m-2; i>=0; i--){
			suffarr[i] = suffarr[i+1];
			if(goalnums.find(painters[i+1]) != goalnums.end())
				suffarr[i] = painters[i+1];
		}

		int answer[m], flag = 0;
		for(int i=0; i<m; i++){
			int notused = repaint[painters[i]][0].size();
			int used = repaint[painters[i]][1].size();

			if(notused != 0){
				answer[i] = *repaint[painters[i]][0].begin();
				repaint[painters[i]][0].erase(answer[i]);
				repaint[painters[i]][1].insert(answer[i]);
			}
			else if(used != 0){
				answer[i] = *repaint[painters[i]][1].begin();
			}
			else if(suffarr[i] != 0){
				int a = suffarr[i];
				if(repaint[a][0].size() != 0)
					answer[i] = *repaint[a][0].begin();
				else{
					answer[i] = *repaint[a][1].begin();
					repaint[a][1].erase(answer[i]);
					repaint[a][0].insert(answer[i]);
				}
			}
			else{
				flag = 1;
				break;
			}
		}

		for(int i=0; i<=n; i++){
			if(repaint[i][0].size() != 0)
				flag = 1;
		}

		if(flag == 1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
			for(int i=0; i<m; i++)
				cout << answer[i]+1 << " ";
			cout << "\n";
		}
	}
}
