#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int lredge[600][599]; //n, m-1
int tdedge[599][600]; //n-1, m
int n, m, k;

int distance(int i1, int j1, int i2, int j2){
	//next cell is above
	if(i1 > i2){
		return tdedge[i2][j1];
	}
	//next cell is below
	else if(i2 > i1){
		return tdedge[i1][j1];
	}
	//next cell is to the left
	else if(j1 > j2){
		return lredge[i1][j2];
	}
	//next cell is to the right
	else if(j2 > j1){
		return lredge[i1][j1];
	}

	assert(1 == 0);
}

int dp[510][510][25];

int32_t main(){
	cin >> n >> m >> k;

	for(int i=0; i<510; i++)
		for(int j=0; j<510; j++)
			for(int k=1; k<25; k++)
				dp[i][j][k] = 1000000000;

	for(int i=0; i<n; i++)
		for(int j=0; j<m-1; j++)
			cin >> lredge[i][j];

	for(int i=0; i<n-1; i++)
		for(int j=0; j<m; j++)
			cin >> tdedge[i][j];

	if(k%2 == 1){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				cout << -1 << " ";
			cout << "\n";
		}
		return 0;
	}

	for(int l=2; l<=k; l+=2){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				for(int r=0; r<4; r++){
					int newx = i + dx[r];
					int newy = j + dy[r];
					if(0 <= newx && newx <= n-1 && 0 <= newy && newy <= m-1){
						dp[i][j][l] = min(dp[i][j][l], dp[newx][newy][l-2]+2*distance(i, j, newx, newy));
					}
				}
			}
		}

	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << dp[i][j][k] << " ";
		}
		cout << "\n";
	}
}
