#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r, c, i, j, k, x, y;
	cin >> r >> c;
	int arr1[r][c], arr2[r][c];
	if(r == 1 && c == 1)
	{
		cout << "0\n";
		exit(0);
	}

	// else if(c == 1)
	// {
	// 	for(i=1; i<r+1; i++)
	// 		cout << i << "\n";
	// 	exit(0);
	// }


		n = min(r, c);

	if(c >= r)
	{
		int count = 3;
		arr1[0][0] = 2;
		for(i=1, j=3; i<n; i++, j+=2)
		{
			arr1[0][i] = j;
			count++;
		}
		for(i=1, j=4; i<n; i++, j+=2)
		{
			arr1[i][0] = j;
			count++;
		}

		if(c > n)
		{
			for(i=n; i<c; i++)
			{
				arr1[0][i] = count;
				count++;
			}
		}
	
		for(i=1; i<r; i++)
		{
			for(j=1; j<c; j++)
			{
				arr1[i][j] = arr1[0][j]*arr1[i][0];
			}
		}

		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				cout << arr1[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
	{

		int count2 = 3;
		arr2[0][0] = 2;
		for(i=1, j=4; i<n; i++, j+=2)
		{
			arr2[0][i] = j;
			count2++;
		}
		for(i=1, j=3; i<n; i++, j+=2)
		{
			arr2[i][0] = j;
			count2++;
		}

		if(r > n)
		{
			for(i=n; i<r; i++)
			{
				arr2[i][0] = count2;
				count2++;
			}
		}


		for(i=1; i<r; i++)
		{
			for(j=1; j<c; j++)
			{
				arr2[i][j] = arr2[0][j]*arr2[i][0];
			}
		}
		// cout << "\n\n";

		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				cout << arr2[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
}