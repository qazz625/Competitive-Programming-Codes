#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, i, j, k, x, y;
	vector<vector<int>> tree;
	queue<int> q;
	cin >> n;
	for(i=0; i<n; i++)
	{
		vector<int> temp;
		tree.push_back(temp);
	}

	for(i=0; i<n-1; i++)
	{
		cin >> x >> y;
		x -= 1;
		y -= 1;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	// cout << "AA";
	int done[n]={0};

	for(i=0; i<n; i++)
	{
		if(tree[i].size() == 1)
		{
			q.push(i);
			done[i] = 1;
		}
	}

	int in;
	// cout << q.size();
	int ans;
	while(q.size() > 1)
	{
		x = q.front();
		q.pop();
		y = q.front();
		ans = y;
		q.pop();

		cout << "? " << x+1 << " " << y+1 << endl;
		cin >> in;
		if(done[in-1] == 0)
		{
			q.push(in-1);
			done[in-1] = 1;
		}

	}

	if(q.size() != 0)
		cout << "! " << q.front()+1 << endl;
	else
		cout << "! " << ans+1 << endl;

}