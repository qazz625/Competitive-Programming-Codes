#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, i, j, k, x, y;
		cin >> n >> m;
		string s;
		cin >> s;
		int arr[m];
		for(i=0; i<m; i++)
			cin >> arr[i];

		int diff[n]={0};

		for(i=0; i<m; i++)
		{
			diff[0]++;
			diff[arr[i]] -= 1;
		}
		diff[0]++;


		for(i=1; i<n; i++)
			diff[i] = diff[i]+diff[i-1];

		int ans[26]={0};
		for(i=0; i<n; i++)
			ans[s[i]-'a'] += diff[i];

		for(i=0; i<26; i++)
			cout << ans[i] << " ";
		cout << "\n";

	}
}