#include<bits/stdc++.h>
using namespace std;

#define int long long

int find(int x, int y, vector<vector<int>> &arr, string &s)
{
	int i, j;
	int count1=0, count2=0;
	for(i=0; i<arr.size()-1; i++)
	{
		if((s[i]-'a') == x)
			count1 += arr[i+1][y];
	}
	for(i=0; i<arr.size()-1; i++)
	{
		if((s[i]-'a') == y)
			count2 += arr[i+1][x];
	}

	return max(count1, count2);
}

int32_t main()
{
	string s;
	cin >> s;
	if(s.size() == 1)
	{
		cout << "1\n";
		return 0;
	}

	int i, j, k, x, y;
	int arr[26]={0};

	for(i=0; i<s.size(); i++)
		arr[s[i]-'a']++;
	int n = s.size();

	vector<vector<int>> arr2;
	for(i=0; i<s.size(); i++)
	{
		vector<int> temp;
		for(j=0; j<26; j++)
			temp.push_back(0);
		arr2.push_back(temp);
	}

	for(i=0; i<26; i++)
	{
		arr2[s.size()-1][i] = 0;
	}
	arr2[s.size()-1][s[s.size()-1]-'a']++;

	for(i=s.size()-2; i>=0; i--)
	{
		for(j=0; j<26; j++)
		{
			arr2[i][j] = arr2[i+1][j];
		}
		arr2[i][s[i]-'a']++;
	}

	// for(i=0; i<arr2.size(); i++)
	// {
	// 	for(j=0; j<26; j++)
	// 	{
	// 		cout << arr2[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }



	vector<int> v;
	char cur = s[0], count=1;

	for(i=1; i<s.size(); i++)
	{
		if(s[i] == cur)
			count++;
		else
		{
			v.push_back(count);
			count = 1;
			cur = s[i];
		}
	}
	v.push_back(count);

	// for(i=0; i<v.size(); i++)
	// 	cout << v[i] << " ";
	// cout << "\n";

	int maxarr[v.size()];
	int ma = -1;

	for(i=v.size()-1; i>=0; i--)
	{
		ma = max(ma, v[i]);
		maxarr[i] = ma;
	}

	// for(i=0; i<v.size(); i++)
	// 	cout << maxarr[i] << " ";
	// cout << "\n";

	// ma = -1;
	// for(i=0; i<v.size()-1; i++)
	// {
	// 	ma = max(ma, v[i]*maxarr[i+1]);
	// }
	// cout << max(ma, arr[25]) << "\n";
	sort(arr, arr+26);

	ma = -1;
	for(i=0; i<26; i++)
	{
		for(j=i; j<26; j++)
		{

			ma = max(ma, find(i, j, arr2, s));
		}
	}

	cout << max(ma, arr[25]) << "\n";
}