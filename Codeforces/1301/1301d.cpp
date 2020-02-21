#include<bits/stdc++.h>
using namespace std;

void print(vector<pair<int, string>> &v)
{
	cout << "YES\n";
	cout << v.size() << "\n";
	for(int i=0; i<v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}
}

int main()
{
	int n, m, k, x, y, i, j, rem;
	cin >> n >> m >> k;
	int flag = 0;
	vector<pair<int, string>> ans;
	pair<int, string> one, two, three;

	if(n == 1)
	{
		pair<int, string> temp1, temp2;
		temp1.first = min(k, m-1);
		temp1.second = "R";
		k -= (m-1);
		ans.push_back(temp1);

		if(k <= 0)
		{
			print(ans);
			return 0;
		}

		temp2.first = min(k, m-1);
		temp2.second = "L";
		k -= (m-1);
		ans.push_back(temp2);
		if(k <= 0)
		{
			print(ans);
			return 0;
		}

		cout << "NO\n";
		return 0;
	}
	if(m == 1)
	{
		pair<int, string> temp1, temp2;
		temp1.first = min(k, n-1);
		temp1.second = "D";
		k -= (n-1);
		ans.push_back(temp1);

		if(k <= 0)
		{
			print(ans);
			return 0;
		}

		temp2.first = min(k, n-1);
		temp2.second = "U";
		k -= (n-1);
		ans.push_back(temp2);
		if(k <= 0)
		{
			print(ans);
			return 0;
		}

		cout << "NO\n";
		return 0;

	}

	one.first = min(k, n-1);
	one.second = "D";
	k -= (n-1);
	ans.push_back(one);

	if(k <= 0)
	{
		print(ans);
		return 0;
	}

	two.first = min(k, n-1);
	two.second = "U";
	k -= (n-1);
	ans.push_back(two);

	if(k <= 0)
	{
		print(ans);
		return 0;
	}

	three.first = 1;
	three.second = "R";
	k -= 1;
	ans.push_back(three);

	if(k <= 0)
	{
		print(ans);
		return 0;
	}

	for(i=1; i<m; i++)
	{
		if(k >= 3*(n-1))
		{
			pair<int, string> temp;
			temp.first = n-1;
			temp.second = "DLR";
			k -= 3*(n-1);
			ans.push_back(temp);
		}
		else
		{
			x = k/3;
			rem = k%3;
			pair<int, string> temp1, temp2;
			temp1.first = x;
			temp1.second = "DLR";
			if(temp1.first != 0)
				ans.push_back(temp1);
			if(rem != 0)
			{
				temp2.first = 1;
				if(rem == 1)
					temp2.second = "D";
				else
					temp2.second = "DL";
				ans.push_back(temp2);
			}
			
			k = 0;
		}

		if(k <= 0)
		{
			print(ans);
			return 0;
		}

		pair<int, string> temp1, temp2;
		temp1.first = min(k, n-1);
		temp1.second = "U";
		ans.push_back(temp1);
		k -= (n-1);

		if(k <= 0)
		{
			print(ans);
			 return 0;
		}

		if(i != m-1)
		{
			temp2.first = 1;
			temp2.second = "R";
			k -= 1;
			ans.push_back(temp2);

			if(k <= 0)
			{
				print(ans);
				return 0;
			}
		}

		else
		{
			temp2.first = min(k, m-1);
			temp2.second = "L";
			k -= (m-1);
			ans.push_back(temp2);

			if(k <= 0)
			{
				print(ans);
				return 0;
			} 
		}
		
	}
		cout << "NO\n";
}
