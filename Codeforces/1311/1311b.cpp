#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, i, j, k, x, y;
		cin >> n >> m;
		int arr[n];
		int lol[n];
		for(i=0; i<n; i++)
		{
			cin >> arr[i];
			lol[i] = arr[i];
		}
		int p[m];
		for(i=0; i<m; i++)
			cin >> p[i];

		sort(p, p+m);
		int flag = 0;

		for(j=0; j<n; j++)
		{
			for(i=0; i<m; i++)
			{
				if(arr[p[i]-1] > arr[p[i]])
					swap(arr[p[i]-1], arr[p[i]]);
			}
		}

		sort(lol, lol+n);
		for(i=0; i<n; i++)
		{
			if(lol[i] != arr[i])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			cout << "NO\n";
		else
			cout << "YES\n";

	}
}