#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

set<vector<vector<char>>> reachable, finished;

void dfs(vector<vector<char>> &board, int turn){
	int empty = 0;
	for(int i=0; i<3; i++){
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_'){
			finished.insert(board);
			return;
		}
	}

	for(int i=0; i<3; i++){
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '_'){
			finished.insert(board);
			return;
		}
	}

	bool one = board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_';
	bool two = board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_';

	if(one || two){
		finished.insert(board);
		return;
	}

	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(board[i][j] == '_')
				empty++;

	if(empty == 0){
		finished.insert(board);
		return;
	}

	reachable.insert(board);


	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j] == '_'){
				if(turn == 0)
					board[i][j] = 'O';
				else
					board[i][j] = 'X';

				if(reachable.find(board) == reachable.end() && finished.find(board) == finished.end()){
					dfs(board, turn^1);
				}

				board[i][j] = '_';
			}
		}
	}
}

int32_t main(){
	vector<vector<char>> board = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
	dfs(board, 1);

	int t;
	cin >> t;
	while(t--){
		vector<vector<char>> arr(3, vector<char>(3, '_'));

		for(int i=0; i<3; i++){
			string s;
			cin >> s;
			for(int j=0; j<3; j++)
				arr[i][j] = s[j];
		}

		if(finished.find(arr) != finished.end())
			cout << "1\n";
		else if(reachable.find(arr) != reachable.end())
			cout << "2\n";
		else
			cout << "3\n";
	}
}
