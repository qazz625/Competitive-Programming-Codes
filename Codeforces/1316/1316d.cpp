#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, i, j, k, x, y;
	int arr[n+2][n+2];
	cin >> n;

	for(i=0; i<n+2; i++)
		for(j=0; j<n+2; j++)
			arr[i][j] = -1;

	int flag = 0;
	int input[n][2*n];
	for(j=0; j<n; j++)
	{
		for(i=0; i<2*n;  i+=2)
		{
			cin >> x >> y;
			input[j][i] = x;
			input[j][i+1] = x+1;
		}
	}

	for(j=1; j<=n; j++)
	{
		for(i=1; i<=2*n+2; i+=2)
		{
			x = arr[j][i];
			y = arr[j][i+1];
			if(x == j and y == (i+1)/2)
			if
		}
	}
}