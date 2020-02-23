#include<bits/stdc++.h>
using namespace std;

void print(vector<pair<int, int>> &pv)
{
	for(int i=0; i<pv.size(); i++)
	{
		cout << pv[i].first+1 << " " << pv[i].second+1 << "\n";
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, i, j, x, y;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<char> ss;
		for(i=0; i<n; i++)
			ss.push_back(s[i]);

		char cur = '(';
		int ind = 0;
		vector<pair<int, int>> ans;
		for(ind=0; ind<2*k-2; ind++)
		{

			if(cur == '(' && ss[ind] != cur)
			{
				int ind2;
				for(i=ind; i<n; i++)
				{
					if(ss[i] == '(')
					{
						ind2 = i;
						break;
					}
				}
				pair<int, int> temp;
				temp.first = ind;
				temp.second = ind2;
				ans.push_back(temp);

				for(i=ind, j=ind2; i<j; i++, j--)
				{
					char abc = ss[i];
					ss[i] = ss[j];
					ss[j] = abc;
				}
			}

			if(cur == ')' && ss[ind] != cur)
			{
				int ind2;
				for(i=ind; i<n; i++)
				{
					if(ss[i] == ')')
					{
						ind2 = i;
						break;
					}
				}
				pair<int, int> temp;
				temp.first = ind;
				temp.second = ind2;
				ans.push_back(temp);

				for(i=ind, j=ind2; i<j; i++, j--)
				{
					char abc = ss[i];
					ss[i] = ss[j];
					ss[j] = abc;
				}
			}

			if(cur == '(')
				cur = ')';
			else
				cur = '(';

		}

		
		cur = '(';
		int lim = (n-2*k+2)/2;
		for(ind=2*k-2; ind<2*k-2+lim; ind++)
		{
			if(cur == '(' && ss[ind] != cur)
			{
				int ind2;
				for(i=ind; i<n; i++)
				{
					if(ss[i] == '(')
					{
						ind2 = i;
						break;
					}
				}
				pair<int, int> temp;
				temp.first = ind;
				temp.second = ind2;
				ans.push_back(temp);

				for(i=ind, j=ind2; i<j; i++, j--)
				{
					char abc = ss[i];
					ss[i] = ss[j];
					ss[j] = abc;
				}
			}
		}

		cout << ans.size() << "\n";
		print(ans);
	}

	return 0;
}