#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, m;
	cin >> n >> m;
	long long mod = 1000000007;
	int i, j, k, x, y;
	vector<vector<vector<long long>>> dparr;
	if(m == 1)
	{
		cout << n*(n+1)/2 << "\n";
	}
	else {
	for(x=1; x<=n; x++)
	{
		vector<vector<long long>> dp;

		vector<long long> temp;
		for(i=0; i<x; i++)
			temp.push_back(1);

		dp.push_back(temp);
		for(i=1; i<m; i++)
		{
			vector<long long> lol;
			long long su = 0;
			for(j=0; j<x; j++)
			{
				su += dp[i-1][j];
				lol.push_back(su);
				su %= mod;
			}
			
			dp.push_back(lol);
			// cout << i << "\n";
		}
		dparr.push_back(dp);
		// cout <<"AA";
	}

	long long ans = 0;
	for(i=1; i<n+1; i++)
	{
		for(j=i; j<n+1; j++)
		{
			long long su1 = 0;
			for(k=0; k<dparr[i-1][m-2].size(); k++)
			{
				su1 += dparr[i-1][m-2][k];
				
			}
			su1 %= mod;
			
			long long su2 = 0;
			for(k=0; k<dparr[n-j][m-2].size(); k++)
			{
				su2 += dparr[n-j][m-2][k];
				
			}
			su2 %= mod;
			
			ans += (su1*su2)%mod;
			
		}
		ans %= mod;
	}
	cout << ans << "\n";}
}