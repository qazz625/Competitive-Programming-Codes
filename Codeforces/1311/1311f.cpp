#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, i, j, k, x, y;
	cin >> n;
	vector<pair<int, int>> vp;
	for(i=0; i<n; i++)
	{
		pair<int, int> temp;
		cin >> x;
		temp.first = x;
		temp.second = 0;
		vp.push_back(temp);
	}
	for(i=0; i<n; i++)
	{
		cin >> x;
		vp[i].second = x;
	}

	sort(vp.begin(), vp.end());

	vector<pair<int, int>> pfx;
	vector<int> zeropfx;
	int neg=0, pos=0, zero=0;
	map<int, vector<int>> mp;
	map<int, vector<int>> mppfx;
	for(i=0; i<n; i++)
	{
		pair<int, int> temp;
		mp[vp[i].second].push_back(vp[i].first);
		if(vp[i].second < 0)
			neg++;
		else if(vp[i].second > 0)
			pos++;
		else
			zero++;
		temp.first = pos;
		temp.second = neg;
		pfx.push_back(temp);
		zeropfx.push_back(zero);
	}

	for(auto x: mp)
	{
		int su = 0;
		for(auto y: x.second)
		{
			su += y;
			mppfx[x.first].push_back(su);
		}
	}

	for(auto x: mp)
	{
		cout << x.first << ": ";
		for(auto y:x.second)
			cout << y << " ";
		cout << "\n";
	}

	cout << "\n";

	for(auto x: mppfx)
	{
		cout << x.first << ": ";
		for(auto y: x.second)
			cout << y << " ";
		cout << "\n";
	}

	int ans = 0;

	for(i=1; i<n-1; i++)
	{
		
	}



	for(i=0; i<n; i++)
	{
		cout << vp[i].first << " " << vp[i].second << "\n";
	}


}