#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		int i, j, k, x, y;
		cin >> s;
		int n = s.size();
		int ind1, ind2;

		for(i=0, j=n-1; i<n; i++, j--)
		{
			// cout << s[i] << " " << s[j] << endl;
			if(s[i] != s[j])
			{
				ind1 = i;
				ind2 = j;
				break;
			}
			// cout << i << " " << n << "\n";
		}


		cout << ind1 << " " << ind2 << "\n";
	}
}