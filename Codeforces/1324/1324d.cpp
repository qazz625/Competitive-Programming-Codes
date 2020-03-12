#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
	int n, i, j, k, x, y;
	cin >> n;
	int arr1[n], arr2[n];
	vector<pair<int, int>> v;
	for(i=0; i<n; i++)
	{
		pair<int, int> temp;
		v.push_back(temp);
	}
	for(i=0; i<n; i++)
	{
		cin >> x;
		v[i].first = x;
	}
	for(i=0; i<n; i++)
	{
		cin >> x;
		v[i].second = x;
	}

	vector<vector<int>> diff;
	for(i=0; i<n; i++)
	{
		vector<int> temp;
		temp.push_back(v[i].first-v[i].second);
		temp.push_back(v[i].first);
		temp.push_back(v[i].second);
		diff.push_back(temp);
	}

	sort(diff.begin(), diff.end());

	int res = 0;
	for(i=0; i<n; i++)
	{
		int req = -(diff[i][1]-diff[i][2])+1;
		int s=i+1, e=n-1;
		int ans = -1;
		while(s <= e)
		{
			int mid = (s+e)/2;
			if(diff[mid][0] < req)
			{
				s = mid+1;
			}
			else
			{
				ans = mid;
				e = mid-1;
			}
		}

		if(ans != -1)
			res += n-ans;

	}

	cout << res << "\n";

}