#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n];
		int i, j, k, x, y;
		for(i=0; i<n; i++)
			cin >> arr[i];
		int lol = -1;

		vector<int> arr2;
		for(i=1; i<n-1; i++)
		{
			if(arr[i] != -1 && (arr[i+1] == -1 || arr[i-1] == -1))
				arr2.push_back(arr[i]);
		}

		if(arr[0] != -1 && arr[1] == -1)
			arr2.push_back(arr[0]);

		if(arr[n-1] != -1 && arr[n-2] == -1)
			arr2.push_back(arr[n-1]);
		

		for(i=0; i<n-1; i++)
		{
			if(arr[i] != -1 && arr[i+1] != -1)
				lol = max(lol, abs(arr[i]-arr[i+1]));
		}

		if(arr2.size() == 0)
		{
			cout << "0 10\n";
			continue;
		}

		sort(arr2.begin(), arr2.end());
		// cout << "LL ";
		// for(i=0; i<arr2.size(); i++)
		// 	cout << arr2[i] << " ";
		// cout << "\n";

		x = (arr2[0]+arr2[arr2.size()-1])/2;
		cout << max(lol, max(x-arr2[0], arr2[arr2.size()-1]-x)) << " " << x << "\n";
	}
}