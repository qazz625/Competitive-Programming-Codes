#include<bits/stdc++.h>
using namespace std;

// void prlong long int(long long int arr[], long long int n)
// {
// 	for(long long int i=0; i<n; i++)
// 		cout << arr[i] << " ";
// 	cout << "\n";
// }

// void prlong long int(vector<long long int> &arr)
// {
// 	for(long long int i=0; i<arr.size(); i++)
// 		cout << arr[i] << " ";
// 	cout << "\n";
// }

// void prlong long int(vector<vector<long long int>> &arr)
// {
// 	for(long long int i=0; i<arr.size(); i++)
// 	{
// 		cout << i << ": ";
// 		for(long long int j=0; j<arr[i].size(); j++)
// 		{
// 			cout << arr[i][j] << " ";
// 		}
// 		cout << "\n";
// 	}
// }

int main()
{
	long long int n, m, i;
	cin >> n >> m;
	long long int arr[n];
	vector<vector<long long int>> mods;
	for(i=0; i<m; i++)
	{
		vector<long long int> temp;
		mods.push_back(temp);
	}

	long long int j, k, x, y, a, b;

	for(i=0; i<n; i++)
		cin >> arr[i];

	sort(arr, arr+n);

	// prlong long int(arr, n);

	long long int pfx[n];
	long long int sum = 0;
	for(i=0; i<n; i++)
	{
		sum += arr[i];
		pfx[i] = sum;
	}
	for(i=0; i<m; i++)
	{
		sum = 0;
		// cout << "i" << i << "\n";
		for(j=i; j<n; j+=m)
		{
			sum += arr[j];
			mods[i%m].push_back(sum);
		}
	}

	// prlong long int(mods);

	vector<long long int> ans;

	// for(i=0; i<m; i++)
	// 	ans.push_back(arr[i]);

	// prlong long int(pfx, n);
	// prlong long int(ans);

	sum = 0;
	for(i=0; i<n; i++)
	{
		sum += mods[i%m][i/m];
		// cout << sum << " ";
		ans.push_back(sum);
	}
	// prlong long int(ans);
	for(i=0; i<ans.size(); i++)
		cout << ans[i] << " ";


}