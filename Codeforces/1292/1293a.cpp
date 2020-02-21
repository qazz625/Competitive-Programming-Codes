#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, s, k, i, j, x, y;
		cin >> n >> s >> k;
		set<int> se;
		for(i=0; i<k; i++)
		{
			cin >> x;
			se.insert(x);
		}

		int count1 = 0;
		int ind1 = s, flag = 0;
		while(ind1 >= 1)
		{
			if(se.find(ind1) == se.end())
			{
				flag = 1;
				break;
			}
			// cout << "D" << ind1 << "\n";
			count1++;
			ind1--;
		}
		if(flag == 0)
			count1 = 1000000005;
		flag = 0;

		int count2=0, ind2 = s;
		while(ind2 <= n)
		{
			if(se.find(ind2) == se.end())
			{
				flag = 1;
				break;
			}
			// cout << "U" << ind2 << "\n";
			count2++;
			ind2++;
		}
		if(flag == 0)
			count2 = 1000000005;

		cout << min(count1, count2) << "\n";
	}
}