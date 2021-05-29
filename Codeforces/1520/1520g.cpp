#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int inf = 1ll<<60;

int mat[2050][2050];
int visited1[2050][2050];
int ans[2050][2050];

struct qnode{
	int x, y;
	int dist;
};

int n, m, w;

void bfs(int sx, int sy){
	queue<qnode> q;

	qnode initial;
	initial.x = sx; initial.y = sy;
	initial.dist = 0;
	visited1[sx][sy] = 1;
	q.push(initial);

	while(q.size() != 0){
		qnode fr = q.front();
		for(int i=0; i<4; i++){
			int newx = fr.x+dx[i];
			int newy = fr.y+dy[i];
			if(0 <= newx && newx < n && 0 <= newy && newy < m && mat[newx][newy] != -1 && visited1[newx][newy] == 0){
				visited1[newx][newy] = 1;
				qnode newnode;
				newnode.x = newx;
				newnode.y = newy;
				newnode.dist = fr.dist + 1;
				q.push(newnode);
			}
		}
		ans[fr.x][fr.y] = fr.dist;
		q.pop();
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> w;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> mat[i][j];

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			visited1[i][j] = 0;


	bfs(0, 0);

	int sdist = inf;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(mat[i][j] > 0 && visited1[i][j] == 1)
				sdist = min(sdist, mat[i][j]+w*ans[i][j]);


	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			visited1[i][j] = 0;
			ans[i][j] = 0;
		}
	}
	
	bfs(n-1, m-1);

	int ddist = inf;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(mat[i][j] > 0 && visited1[i][j] == 1)
				ddist = min(ddist, mat[i][j]+w*ans[i][j]);


	int ans1 = sdist + ddist;
	int ans2;
	if(visited1[0][0] == 1)
		ans2 = w*ans[0][0];
	else
		ans2 = inf;

	if(ans1 >= inf && ans2 >= inf){
		cout << -1 << "\n";
	}
	else{
		cout << min(ans2, ans1) << "\n";
	}

}
