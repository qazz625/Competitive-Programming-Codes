#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		string s;
		cin >> n;
		cin >> s;
		int i, j, k, x, y;
		map<pair<int, int>, vector<int>> mp;
		pair<int, int> ttemp;
		ttemp.first = 0;
		ttemp.second = 0;
		mp[ttemp].push_back(0);

		int ind = -1, inix = 0, iniy = 0;
		for(i=0; i<n; i++)
		{
			if(s[i] == 'U')
				iniy++;
			else if(s[i] == 'D')
				iniy--;
			else if (s[i] == 'R')
				inix++;
			else
				inix--;
			pair<int, int> temp;
			temp.first = inix;
			temp.second = iniy;
			mp[temp].push_back(i+1);
		}

		// for(auto x: mp)
		// {
		// 	cout << x.first.first << " " << x.first.second << "\n";
		// 	for(auto y: x.second)
		// 		cout << y << " ";
		// 	cout << "\n";
		// }
		// cout << "\n";

		int ans = 99999999;
		int ind1, ind2;
		for(auto x: mp)
		{
			for(i=1; i<x.second.size(); i++)
			{
				if(x.second[i]-x.second[i-1] < ans)
				{
					ans = x.second[i]-x.second[i-1];
					ind1 = x.second[i-1];
					ind2 = x.second[i];
				}
			}
		}
		if(ans == 99999999)
		{
			cout << "-1\n";
		}
		
		else
			cout << ind1+1 << " " << ind2 << "\n";

	}
}