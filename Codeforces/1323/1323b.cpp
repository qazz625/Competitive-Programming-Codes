#include<bits/stdc++.h>
using namespace std;

#define int long long


int32_t main()
{
	int n, m, k, i, j, x, y;
	cin >> n >> m >> k;
	int arr1[n], arr2[m];
	for(i=0; i<n; i++)
		cin >> arr1[i];
	for(j=0; j<m; j++)
		cin >> arr2[j];

	vector<int> one, two;
	int count = 0;
	for(i=0; i<n; i++)
	{
		if(arr1[i] == 1)
			count += 1;
		else
		{
			if(count != 0)
				one.push_back(count);
			count = 0;
		}
	}
	if(count != 0)
		one.push_back(count);

	// for(i=0; i<one.size(); i++)
	// 	cout << one[i] << " ";
	// cout << "\n";

	count = 0;

	for(i=0; i<m; i++)
	{
		if(arr2[i] == 1)
			count += 1;
		else
		{
			if(count != 0)
				two.push_back(count);
			count = 0;
		}
	}
	if(count != 0)
		two.push_back(count);

	// for(i=0; i<two.size(); i++)
	// 	cout << two[i] << " ";
	// cout << "\n";

	set<pair<int, int>> fact;
	int sq = sqrt(k);
	for(i=1; i<=sq; i++)
	{
		if(k%i == 0)
		{
			pair<int, int> temp;
			temp.first = i;
			temp.second = k/i;
			fact.insert(temp);
		}
	}

	// for(auto x: fact)
	// 	cout << x.first << " " << x.second << "\n";

	int ans = 0;
	for(auto x: fact)
	{
		int su1=0, su2=0;
		for(i=0; i<two.size(); i++)
		{
			int lol = two[i]-x.second+1;
			if(lol < 0)
				lol = 0;
			su1 += lol;
		}
		for(i=0; i<one.size(); i++)
		{
			int lol = one[i]-x.first+1;
			if(lol < 0)
				lol = 0;
			ans += su1*lol;
		}

		if(x.first == x.second)
			continue;

		su1=0, su2=0;

		for(i=0; i<two.size(); i++)
		{
			int lol = two[i]-x.first+1;
			if(lol < 0)
				lol = 0;
			su1 += lol;
		}
		for(i=0; i<one.size(); i++)
		{
			int lol = one[i]-x.second+1;
			if(lol < 0)
				lol = 0;
			ans += su1*lol;
		}



	}

	cout << ans << "\n";

}