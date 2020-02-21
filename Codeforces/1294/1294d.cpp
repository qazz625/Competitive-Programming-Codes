#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q, x, i, j, k, n;
	set<int> elem;
	int curmex=0;
	cin >> q >> x;

	while(q--)
	{
		cin >> n;
		if(elem.find(n) != elem.end())
		{
			int s = 1;
			int e = (1000000000 - n)/x;
			int ans=-1;
			while(s <= e)
			{
				int mid = (s+e)/2;
				if(elem.find(n+mid*x) == elem.end())
				{
					ans = mid;
					e = mid-1;
				}
				else
				{
					s = mid+1;
				}
			}

			elem.insert(n+ans*x);
		}

		else
		{
			int s = 0;
			int e = (n-curmex)/x;
			int ans;
			while(s <= e)
			{
				int mid = (s+e)/2;
				if(elem.find(n-mid*x) == elem.end())
				{
					ans = mid;
					s = mid+1;
				}
				else
					e = mid-1;
			}
			elem.insert(n-ans*x);
		}

		// for(auto x: elem)
		// {
		// 	cout << x << " ";
		// }
		// cout << "\n";



		while(elem.find(curmex) != elem.end())
		{
			curmex++;
		}
			cout << curmex << "\n";



	}
}