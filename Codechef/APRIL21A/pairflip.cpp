#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int ans;
int n, m, difficulty;

bool check(int current, vector<vector<char>> &final){
	// debug(current);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			bool bit = (1<<(n*m-1-i*m-j))&current;
			if(final[i][j]-'0' == bit || final[i][j] == '?')
				continue;
			return false;
		}
	}
	return true;
}

struct grid{
	int depth, integerrep;
	vector<vector<int>> seq;
	vector<char> rowcol;
	grid(int num, int d){
		depth = d;
		
		integerrep = num;
	}
};

void solve(vector<vector<int>> &current, vector<vector<char>> &final){
	int visited[1<<(n*m)]={0};
	int num = 0;
	int mult = 1;
	for(int i=n-1; i>=0; i--){
		for(int j=m-1; j>=0; j--){
			num += mult*current[i][j];
			mult <<= 1;
		}
	}

	grid source(num, 0);

	queue<grid> q;
	q.push(source);
	visited[source.integerrep] = 1;


	while(q.size() != 0){
		int current = q.front().integerrep;
		if(check(current, final)){
			cout << q.front().depth << "\n";
			if(difficulty == 0)
				return;
			for(int i=0; i<q.front().seq.size(); i++){
				cout << q.front().rowcol[i] << " ";
				for(auto x: q.front().seq[i])
					cout << x+1 << " ";
				cout << "\n";
			}
			return;
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				for(int k=0; k<m; k++){
					if(j != k){
						current ^= (1<<(n*m-1-i*m-j));
						current ^= (1<<(n*m-1-i*m-k));
						if(visited[current] == 0){
							grid g(current, q.front().depth+1);
							visited[g.integerrep] = 1;
							g.seq = q.front().seq;
							g.seq.push_back({i, j, k});
							g.rowcol = q.front().rowcol;
							g.rowcol.push_back('R');
							q.push(g);
						}
						current ^= (1<<(n*m-1-i*m-j));
						current ^= (1<<(n*m-1-i*m-k));
					}
				}
			}
		}

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					if(j != k){
						current ^= (1<<(n*m-1-j*m-i));
						current ^= (1<<(n*m-1-k*m-i));
						if(visited[current] == 0){
							grid g(current, q.front().depth+1);
							visited[g.integerrep] = 1;
							g.seq = q.front().seq;
							g.seq.push_back({i, j, k});
							g.rowcol = q.front().rowcol;
							g.rowcol.push_back('C');
							q.push(g);
						}
						current ^= (1<<(n*m-1-j*m-i));
						current ^= (1<<(n*m-1-k*m-i));
					}
				}
			}
		}

		q.pop();
	}

	cout << "-1\n";

}


int32_t main(){
	int t;
	cin >> t;
	while(t--){

		ans = -1;

		cin >> n >> m >> difficulty;
		assert(n*m <= 16);
		vector<vector<int>> initial(n, vector<int>(m));
		vector<vector<char>> final(n, vector<char>(m));

		for(int i=0; i<n; i++){
			string s;
			cin >> s;
			for(int j=0; j<m; j++)
				initial[i][j] = s[j]-'0';
		}

		for(int i=0; i<n; i++){
			string s;
			cin >> s;
			for(int j=0; j<m; j++)
				final[i][j] = s[j];
		}


		solve(initial, final);
	}
}
