#include<bits/stdc++.h>
using namespace std;

#define int long long


int32_t main()
{
	int n, m;
	cin >> n >> m;
	int arr[n];
	int i, j, k, x, y;
	for(i=0; i<n; i++)
		cin >> arr[i];

	if(n > 10000)
	{
		cout << "0\n";
		return 0;
	}

	int prod=1;
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			prod *= abs(arr[i]-arr[j]);
			prod %= m;
		}
	}

	cout << prod << "\n";

}