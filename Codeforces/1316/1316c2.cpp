#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
	int n, m, i, j, k, p;
	cin >> n >> m >> p;
	vector<int> v1(n), v2(m);
	for(i=0; i<n; i++)
	{
		cin >> j;
		v1[i] = j;
	}
	for(i=0; i<m; i++)
	{
		cin >> j;
		v2[i] = j;
	}

	int ans = 0;
	for(i=0; i<n; i++)
		if(v1[i]%p != 0)
		{
			ans += i;
			break;
		}
	for(i=0; i<m; i++)
		if(v2[i]%p != 0)
		{
			ans += i;
			break;
		}
	cout << ans << "\n";
}