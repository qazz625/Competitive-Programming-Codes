#include<bits/stdc++.h>
using namespace std;

int solve(string &s, int jump)
{
	int ind = -1;
	int n = s.size(), i, j;
	while(ind < n)
	{
		int jumpto = -1, lol=0;
		for(i=ind+1, j=0; j<jump; i++, j++)
		{
			if(i == n)
			{
				lol = 1;
				break;
			}

			if(s[i] == 'R')
				jumpto = i;

		}
		if(lol == 1)
			break;
		if(jumpto == -1)
			return -1;

		ind = jumpto;
	}

	return 1;

}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, i, j, k, x, y;
		string s;
		cin >> s;
		n = s.size();

		int start=1, end=n+1;
		int res;
		while(start <= end)
		{
			int mid = (start+end)/2;
			int ans = solve(s, mid);
			if(ans == -1)
				start = mid+1;
			else
			{
				res = mid;
				end = mid-1;
			}
		}
		cout << res << "\n";
	}
}