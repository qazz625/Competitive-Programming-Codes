#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		int n;
		cin >> n;
		cin >> s;
		int i, j, k, x, y;
		string arr[s.size()];
		for(i=0; i<n; i++)
		{
			string temp="", temp2="";
			for(j=i; j<n; j++)
				temp += s[j];

			if((n-i)%2 == 0)
				for(j=0; j<i; j++)
					temp2 += s[j];
			else
				for(j=i-1; j>=0; j--)
					temp2 += s[j];

			arr[i] = temp+temp2;
		}

		for(i=0; i<n; i++)
			cout << arr[i] << "\n";

		string mi = "";
		for(i=0; i<n; i++)
			mi += 'z';

		// reverse(s.begin(), s.end());
		// arr[n-1] = s;

		vector<int> blocked;

		int ind;
		for(i=0; i<n; i++)
		{
			if(arr[i] < mi)
			{
				mi = arr[i];
				ind = i;
			}
		}

		cout << mi << "\n" << ind+1 << "\n";
	}
}