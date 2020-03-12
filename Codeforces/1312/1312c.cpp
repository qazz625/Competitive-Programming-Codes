#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		int n, k, i, j, x;
		cin >> n >> k;
		ll arr[n];
		for(i=0; i<n; i++)
			cin >> arr[i];
		vector<vector<ll>> v;


		for(i=0; i<n; i++)
		{
			vector<ll> temp;
			while(arr[i] != 0)
			{
				temp.push_back(arr[i]%k);
				arr[i] /= k;
			}

			reverse(temp.begin(), temp.end());
			v.push_back(temp);		
		}

		set<int> s;
		int flag = 0, ind;
		for(i=0; i<v.size(); i++)
		{

			for(j=v[i].size()-1, ind=0; j>=0; j--, ind++)
			{
				if(v[i][j] > 1)
					flag = 1;
				else if(v[i][j] == 1 && s.find(ind) != s.end())
					flag = 1;
				else if(v[i][j] == 1)
				{
					s.insert(ind);
				}
			}

		}
		if(flag == 1)
			cout << "NO\n";
		else
			cout << "YES\n";
		// cout << "AA";
	}
}