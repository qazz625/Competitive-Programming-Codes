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
		if(m >= n/2)
		{
			cout << (n*(n+1))/2 - (n-m) << "\n";
			continue;
		}
		cout << "-1\n";


	}
}