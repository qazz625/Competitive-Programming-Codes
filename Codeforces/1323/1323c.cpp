#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, i, j, k, x, y;
	cin >> n;
	string s;
	cin >> s;
	int o=0, c=0;
	for(i=0; i<n; i++)
	{
		if(s[i] == '(')
			o++;
		else
			c++;
	}
	if(o != c){
		cout << "-1\n";
		return 0;
	}

	int arr[n];
	vector<int> zero;
	o=0; c=0;

	for(i=0; i<n; i++)
	{
		if(s[i] == '(')
			o++;
		else
			c++;
		if(o == c)
			zero.push_back(i);
	}

	// for(i=0; i<zero.size(); i++)
	// 	cout << zero[i] << " ";
	// cout << "\n";


	int prev = 0, ans=0;
	for(i=0; i<zero.size(); i++)
	{
		int flag=0, check=0;
		for(j=prev; j<zero[i]; j++)
		{
			if(s[j] == '(')
				check++;
			else
				check--;
			if(check < 0)
				flag = 1;
		}
		if(flag == 1)
			ans += zero[i]-prev+1;
		prev = zero[i]+1;

	}
	cout << ans << "\n";





}