#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, i, j, k, x, y;
		cin >> n;
		int arr[n];
		for(i=0; i<n; i++)
		{
			cin >> arr[i];
		}

		if(n == 1)
		{
			cout << "-1\n";
			continue;
		}

		map<int, vector<int>> ind;
		// for(i=0; i<200010; i++)
		// {
		// 	vector<int> temp;
		// 	ind.push_back(temp);
		// }

		for(i=0; i<n; i++)
		{
			ind[arr[i]].push_back(i);
		}

		int ans = 9999999;
		int prevans = 99999999;

		// for(i=0; i<10; i++)
		// {
		// 	for(j=0; j<ind[i].size(); j++)
		// 	{
		// 		cout << ind[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }

		for(auto itr: ind)
		{
			// cout << ind[i].size() << "\n";
			if(itr.second.size() == 0)
				continue;
			for(j=0; j<itr.second.size()-1; j++)
			{
				// cout << j << " ";
				ans = min(ans, itr.second[j+1]-itr.second[j]);
			}
		}

		if(ans == 9999999)
			cout << "-1\n";
		else
			cout << ans+1 << "\n";
	}
}