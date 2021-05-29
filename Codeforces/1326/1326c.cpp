#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
	int n, k;
	cin >> n >> k;
	int i, j, x, y;
	int mod = 998244353;
	int arr[n];
	for(i=0; i<n; i++)
		cin >> arr[i];

	set<int> s;

	int ans1 = 0;
	for(i=n-k+1; i<=n; i++)
	{
		s.insert(i);
		ans1 += i;
	}

	// for(auto x: s)
	// 	cout << x << " ";
	// cout << "\n";

	int ind=0;
	while(s.find(arr[ind]) == s.end())
		ind++;


	int count = 1;
	int ans2 = 1;
	while(ind != n-1)
	{
		if(s.find(arr[ind+1]) != s.end())
		{
			ans2 *= count;
			ans2 %= mod;
			count = 1;
		}
		else
			count++;
		ind++;
	}

	// ans2 *= count;
	// ans2 %= mod;
	cout << ans1 << " " << ans2 << "\n";
}