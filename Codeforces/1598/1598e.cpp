#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int arr[1010][1010][2];

//0 goes right first
//1 goes down first

int state[1010][1010];

int32_t main(){
	int n, m, q;
	cin >> n >> m >> q;

	arr[n-1][m-1][0] = 0;
	arr[n-1][m-1][1] = 0;

	for(int i=n-2; i>=0; i--){
		arr[i][m-1][1] = 1;
		arr[i][m-1][0] = 0; 
	}

	for(int i=m-2; i>=0; i--){
		arr[n-1][i][1] = 0;
		arr[n-1][i][0] = 1;
	}

	for(int i=n-2; i>=0; i--){
		for(int j=m-2; j>=0; j--){
			arr[i][j][0] = arr[i][j+1][1] + 1;
			arr[i][j][1] = arr[i+1][j][0] + 1; 
		}
	}

	int total = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			total += arr[i][j][0];
			total += arr[i][j][1];
		}
	}

	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<m; j++){
	// 		debug(i, j, arr[i][j][0], arr[i][j][1]);
	// 	}
	// }

	int blocked = 0;

	debug(total);

			for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << "{" << arr[i][j][0] << "," << arr[i][j][1] << "} ";
			}
			cout << "\n";
		}
		cout << "\n";

	while(q--){
		int x, y;
		cin >> x >> y;
		x--; y--;
		if(state[x][y] == 0){

			int sub = 0, flag1 = 0, flag2 = 0, counter = 0;

			for(int i=x-1, j=y-1; i>=0 || j >= 0; i--, j--, counter++){
				debug(i, j, counter, flag1, flag2);
				if(i >= 0 && y-counter >= 0){
					debug(i, y-counter);
					if(state[i][y-counter] == 1)
						flag1 = 1;
					if(flag1 == 0){
						sub += arr[x][y][0]+1;
						arr[i][y-counter][1] -= arr[x][y][0]+1;
					}
				}

				debug(flag1);

				if(j >= 0 && x-counter >= 0){
					if(state[x-counter][j] == 1)
						flag2 = 1;
					if(flag2 == 0){
						sub += arr[x][y][1]+1;
						arr[x-counter][j][0] -= arr[x][y][1]+1;
					}
				}

				if(i >= 0 && j >= 0){

					if(state[i][j] == 1){
						flag1 = 1;
						flag2 = 1;
					}

					if(flag1 == 0){
						sub += arr[x][y][0]+1;
						arr[i][j][1] -= arr[x][y][0]+1;
					}

					if(flag2 == 0){
						sub += arr[x][y][1]+1;
						arr[i][j][0] -= arr[x][y][1]+1;
					}

				}
			}

			sub += arr[x][y][0];
			sub += arr[x][y][1];
			arr[x][y][0] = 0;
			arr[x][y][1] = 0;


			blocked++;

			debug(total, sub);
			cout << total-sub+(n*m - blocked) << "\n";

			total = total-sub;
		}
		else{

			int add = 0;

			if(y < m-1 && state[x][y+1] == 0){
				add += arr[x][y+1][1] + 1 - arr[x][y][0];
				arr[x][y][0] = arr[x][y+1][1] + 1;
			}
			if(x < n-1 && state[x+1][y] == 0){
				add += arr[x+1][y][0] + 1 - arr[x][y][1];
				arr[x][y][1] = arr[x+1][y][0] + 1;

			}


			int counter = 0, flag1 = 0, flag2 = 0;
			for(int i=x-1, j=y-1; i>=0 || j >= 0; i--, j--, counter++){
				if(i >= 0 && y-counter >= 0){
					if(state[i][y-counter] == 1)
						flag1 = 1;
					if(flag1 != 1){
						add += arr[i+1][y-counter][0]+1 - arr[i][y-counter][1];
						arr[i][y-counter][1] = arr[i+1][y-counter][0]+1;
					}
					
				}
				if(j >= 0 && x-counter >= 0){
					if(state[x-counter][j] == 1)
						flag2 = 1;
					if(flag2 != 1){
						add += arr[x-counter][j+1][0]+1 - arr[x-counter][j][0];
						arr[x-counter][j][0] = arr[x-counter][j+1][0]+1;
					}
				}
				if(i >= 0 && j >= 0){
					debug("CC");
					if(state[i][j] == 1){
						flag1 = 1;
						flag2 = 1;
					}

					if(flag1 != 1){
						add += arr[i+1][j][0] + 1 - arr[i][j][0];
						arr[i][j][0] = arr[i+1][j][0] + 1;
					}
					if(flag2 != 1){
						add += arr[i][j+1][1] + 1 - arr[i][j][1];
						arr[i][j][1] = arr[i][j+1][1] + 1;
					}
				}
			} 

			blocked--;

			debug(blocked, total, add);

			cout << total+add+(n*m - blocked) << "\n";

			total = total+add;
		}

		state[x][y] ^= 1;


		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << "{" << arr[i][j][0] << "," << arr[i][j][1] << "} ";
			}
			cout << "\n";
		}
		cout << "\n";
	}



}

//Read the stuff at the top