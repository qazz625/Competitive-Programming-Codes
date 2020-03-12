#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, i, j, k, x, y;
	cin >> n;
	int arr[n];
	for(i=0; i<n; i++)
		cin >> arr[i];



	int dp[n][n][3];

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			dp[i][j][1] = 0;

	for(i=0; i<n; i++)
	{
		dp[i][i][0] = arr[i];
		dp[i][i][2] = arr[i];
		dp[i][i][1] = 1;
	}

	for(i=1; i<n; i++)
	{
		for(j=0, k=j+i; k<n; j++, k++)
		{
			int mi = 99999999;
			int flag = 0;
			for(x=j+1; x<=k; x++)
			{
				if(dp[j][x-1][2] == dp[x][k][0])
				{
					if(x-1-j+1 == 1)
						dp[j][k][0] = dp[j][x-1][0]+1;
					else
						dp[j][k][0] = dp[j][x-1][0];

					if(k-x+1 == 1)
						dp[j][k][2] = dp[x][k][2]+1;
					else
						dp[j][k][2] = dp[x][k][2];

					dp[j][k][1] = dp[j][x-1][1] + dp[x][k][1]-1;
					// cout << j << " " << x << " " << k << " " << dp[j][k][1] << "\n";
					flag = 1;
					break;
				}

			}
			if(flag == 0)
			{
				dp[j][k][0] = arr[j];
				dp[j][k][2] = arr[k];
				dp[j][k][1] = k-j+1;
			}
		}
	}

	cout << dp[0][n-1][1] << "\n";

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			cout << dp[i][j][1] << " ";
		cout << "\n";
	}
}