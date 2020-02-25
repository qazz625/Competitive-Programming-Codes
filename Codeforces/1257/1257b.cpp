#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int a, b;
		cin >> a >> b;
		// cout << a << " " << b << "\n";
		if(a >= b)
		{
			cout << "YES\n";
			continue;
		}

		if(a == 1)
		{
			cout << "NO\n";
			continue;
		}

		if(a == 2 || a == 3)
		{
			if(b == 3)
				cout << "YES\n";
			else
				cout << "NO\n";
			continue;
		}

		cout << "YES\n";


	}
}