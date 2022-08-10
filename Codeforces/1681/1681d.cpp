#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int n, x;


int32_t main(){
	cin >> n >> x;

	queue<pair<int, int>> q;
	q.push({x, 0});
	set<int> s;
	int ans = -1;
	while(q.size() != 0){
		pair<int, int> fr = q.front();
		// print(fr);

		q.pop();
		int l = fr.first;
		int count = 0;
		while(l != 0){
			l /= 10;
			count++;
		}

		if(count == n){
			ans = fr.second;
			break;
		}

		if(count == 19)
			continue;

		int num = fr.first;
		while(num != 0){
			int val = num%10;
			if(val != 0 && val != 1 && s.find(val*fr.first) == s.end()){
				s.insert(val*fr.first);
				debug(val*fr.first);
				q.push({val*fr.first, fr.second+1});
			}
			num /= 10;
		}
	}

	cout << ans << "\n";


}

