#include<bits/stdc++.h>
using namespace std;

vector<string> dp[100][100];

string solve(string &s1, string &s2)
{
	int i, j;
	int n1 = s1.size();
	int n2 = s2.size();
	int val;
	string s;
	if(s1.size() == 0 || s2.size() == 0)
		s = s1+s2;

	if(s1[n1-1]+0 == s2[0]-1)
	{
		cout << "LOL" << "\n";
		int ind = n1-1;
		while(ind != -1 && s1[ind] == s2[n2-1]-1)
		{
			ind--;
		}
		for(i=0; i<=ind; i++)
			s += s1[i];
		s += s2;
	}
	else if(s2[0]+0 == s1[n1-1]-1)
	{
		int ind = 0;
		while(ind != n2 && s2[ind] == s1[n1-1]-1)
		{
			ind++;
		}
		s += s1;
		for(i=ind; i<n2; i++)
			s += s2[i];
		val = n1+n2-ind;
	}
	else
	{
		s = s1+s2;
	}
	return s;
}

void solve2(int x1, int y1, int x2, int y2, string &s)
{
	int i, j, k;
	if(y1 < x1)
	{
		for(i=0; i<dp[x2][y2].size(); i++)
			dp[x1][y2].push_back(dp[x2][y2][i]);
		return;

	}
	else if(y2< x2)
	{
		for(i=0; i<dp[x1][y1].size(); i++)
			dp[x1][y2].push_back(dp[x1][y1][i]);
		return;
	}
	for(i=0; i<dp[x1][y1].size(); i++)
		for(j=0; j<dp[x2][y2].size(); j++)
		{
			cout << dp[x1][y1][i] << " " << dp[x2][y2][j] << "\n";
			dp[x1][y2].push_back(solve(dp[x1][y1][i], dp[x2][y2][j]));
		}

}

int main()
{
	int i, j, k, x, y, n;
	string s;
	cin >> n;
	cin >> s;

	for(i=0; i<n; i++)
	{
		for(j=i; j<n; j++)
		{
			string temp = "";
			for(k=i; k<=j; k++)
				temp += s[k];
			dp[i][j].push_back(temp);
		}
	}


	// for(i=0; i<n; i++)
	// {
	// 	string ll = "";
	// 	ll += s[i];
	// 	dp[i][i].push_back(ll);
	// }

	for(i=1; i<n; i++)
	{
		for(j=0, k=i; j<n-i; j++, k++)
		{
			int mi = 9999999;
			for(x=j; x<=k; x++)
			{
				string s1="", s2="";
				for(y=j; y<x; y++)
					s1 += s[y];
				for(y=x+1; y<=k; y++)
					s2 += s[y];
				// cout << s1 << " " << s2 << "\n";
				cout << j << " " << x << " " << k << "\n";
				if(x == j && s[x+1]-1 == s[x]+0)
					solve2(j, x-1, x+1, k, s);
				else if(x == k && s[x-1]-1 == s[x]+0)
					solve2(j, x-1, x+1, k, s);
				else if(x != j && x != k && (s[x]+0 == s[x-1]-1 || s[x]+0 == s[x+1]-1))
				{
					cout << "KEK\n";
					solve2(j, x-1, x+1, k, s);
				}
			}
			cout << "AA" << j << " " << k << "\n";
			for(auto x: dp[j][k])
				cout << x << " ";
			cout << "\n";
		}
	}

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			for(auto x: dp[i][j])
				cout << x << " ";
			cout << "\n";
		}
		cout << "\n";
	}
	int mi = 999999;
	for(auto x: dp[0][n-1])
	{
		cout << x << " ";
		// mi = min(mi, x.size());
	}
	cout << mi << "\n";

}