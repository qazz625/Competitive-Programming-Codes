#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, i, j, k, x, y, q, pos;
	cin >> n;
	int arr[n];
	for(i=0; i<n; i++)
		cin >> arr[i];

	vector<int> sorted;
	for(i=0; i<n; i++)
	{
		sorted.push_back(arr[i]);
	}
	sort(sorted.begin(), sorted.end(), greater<int>());

	cin >> q;
	while(q--)
	{
		cin >> k >> pos;
		multiset<int> temp;
		for(i=0; i<k; i++)
			temp.insert(sorted[i]);

		vector<int> ans;

		for(i=0; i<n; i++)
		{
			if(temp.find(arr[i]) != temp.end())
			{
				ans.push_back(arr[i]);
				temp.erase(temp.find(arr[i]));
			}
		}

		// for(i=0; i<n; i++)
		// 	cout << ans[i] << " ";
		// cout << "\n";

		cout << ans[pos-1] << "\n";
	}
}