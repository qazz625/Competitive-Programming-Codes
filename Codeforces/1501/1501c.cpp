#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int MAXA = 3000000;

vector<int> freq[3000000];
vector<pair<int, int>> pairs[5000100];

int random(int lower, int upper) 
{ 
    int i; 
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num;
} 


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	srand(time(0));

	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
		freq[arr[i]].push_back(i);
	}
	// print(arr, n);

	vector<int> dup;
	int maxfreq = -1, maxfreqind = -1;
	for(int i=0; i<MAXA; i++){
		if(freq[i].size() > 1)
			dup.push_back(i);
		if((int)freq[i].size() > maxfreq){
			maxfreq = freq[i].size();
			maxfreqind = i;
		}
	}

	if(dup.size() >= 2){
		cout << "YES\n";
		cout << freq[dup[0]][0]+1 << " " << freq[dup[1]][0]+1 << " ";
		cout << freq[dup[0]][1]+1 << " " << freq[dup[1]][1]+1 << "\n";
		return 0;
	}


	if(maxfreq >= 4){
		cout << "YES\n";
		for(int i=0; i<4; i++){
			cout << freq[maxfreqind][i]+1 << " ";
		}
		cout << "\n";
		return 0;
	}

	vector<pair<int, int>> arr2;
	for(int i=0; i<MAXA; i++){
		if((int)freq[i].size() != 0)
			arr2.push_back({i, freq[i][0]});
	}

	// print(arr2);

	if(arr2.size() <= 10000){
		// debug(maxfreq);
		// debug(maxfreqind);
		if(maxfreq >= 2){
			for(int i=0; i<n; i++){
				for(int j=i+1; j<n; j++){
					if(arr[i] != maxfreqind && arr[i] + arr[j] == 2*maxfreqind){
						cout << "YES\n";

						cout << freq[maxfreqind][0]+1 << " " << freq[maxfreqind][1]+1 << " ";
						cout << i+1 << " " << j+1 << "\n";
						return 0;
					}
				}
			}
		}
		// debug("AA");

		for(int i=0; i<arr2.size(); i++){
			for(int j=i+1; j<arr2.size(); j++){
				pairs[arr2[i].first+arr2[j].first].push_back({arr2[i].second, arr2[j].second});
			}
		}

		// for(int i=0; i<10; i++){
		// 	print(pairs[i]);
		// }

		int flag = 0;
		for(int i=0; i<5000010; i++){
			if(pairs[i].size() > 1){
				flag = 1;
				cout << "YES\n";
				cout << pairs[i][0].first+1 << " " << pairs[i][0].second+1 << " ";
				cout << pairs[i][1].first+1 << " " << pairs[i][1].second+1 << "\n";
				break;
			}
		}

		if(flag == 0){
			cout << "NO\n";
		}
		return 0;
	}

	set<pair<pair<int, int>, pair<int, int>>> s;
	cout << "YES\n";
	for(int i=0; i<1000000; i++){
		int n = arr2.size();
		int a = random(0, n-4);
		int b = random(a+1, n-3);
		int c = random(b+1, n-2);
		int d = random(c+1, n-1);

		if(s.find({{a, b}, {c, d}}) != s.end())
			continue;

		else{
			s.insert({{a, b}, {c, d}});
			if(arr2[a].first+arr2[d].first == arr2[b].first+arr2[c].first){
				cout << arr2[a].second+1 << " " << arr2[d].second+1 << " ";
				cout << arr2[b].second+1 << " " << arr2[c].second+1 << "\n";
				break;
			}
		}
	}
}
