#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		// ios_base::sync_with_stdio(false);
		// cin.tie(NULL);
		
		int n, i, j, k, x, y;
		cin >> n;
		int arr[n];
		for(i=0; i<n; i++)
			cin >> arr[i];

		int ind = 1;
		int done[n+1]={0};

		vector<int> ans;

		ans.push_back(arr[0]);
		done[arr[0]] = 1;
		int ind2 = 1;

		int flag=0, curmax=arr[0];

		while(ind2 != n)
		{
			// cout << ind << " " << ind2 << " " << arr[ind2] << "\n";
			// cout << "LOL";
			// for(i=0; i<n+1; i++)
			// 	cout << done[i] << " ";
			// cout << "\n";
			int temp;
			if(arr[ind2] == arr[ind2-1])
			{
				while(done[ind] == 1)
					ind++;
				ans.push_back(ind);
				done[ind] = 1;
			}
			else
			{
				ans.push_back(arr[ind2]);
				done[arr[ind2]] = 1;
			}

			ind2++;
		}

		int ma = -1;
		for(i=0; i<n; i++)
		{
			ma = max(ma, ans[i]);
			if(arr[i] != ma)
			{
				flag = 1;
				break;
			}

		}

		if(flag == 1)
		{
			cout << -1 << "\n";
			continue;
		}

		for(i=0; i<n; i++)
			cout << ans[i] << " ";
		cout << "\n";


	}
}