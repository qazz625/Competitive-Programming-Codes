#include<bits/stdc++.h>
using namespace std;

void print(multiset<int> se)
{
	for(auto x: se)
		cout << x << " ";
	cout << "\n";
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int i, j, k, x, y;
		int n, m, csum=0, cfsum=0;
		cin >> n >> m;
		int arr1[n], arr2[m];
		for(i=0; i<n; i++)
		{
			cin >> arr1[i];
			csum += arr1[i];
		}
		string s1, s2;
		cin >> s1;

		for(i=0; i<m; i++)
		{
			cin >> arr2[i];
			cfsum += arr2[i];
		}
		cin >> s2;

		multiset<int> p1a, p1d, p2a, p2d;

		for(i=0; i<n; i++)
		{
			if(s1[i] == 'A')
				p1a.insert(arr1[i]);
			else
				p1d.insert(arr1[i]);
		}

		for(i=0; i<m; i++)
		{
			if(s2[i] == 'A')
				p2a.insert(arr2[i]);
			else
				p2d.insert(arr2[i]);
		}

		print(p1a);
		print(p1d);
		print(p2a);
		print(p2d);

		vector<int> chef, chefina;
		while(true)
		{
			chef.push_back(csum-cfsum);
			int flag = 0;
			if(p1a.size() != 0 && p2d.size() != 0)
			{
				auto end = p2d.end();
				auto start = p1a.begin();
				end--;
				int x = *end;
				int y = *start;
				cout << "AA"<< x << " " << y << "\n";
				p2d.erase(p2d.find(x));
				cfsum -= x;
				p1a.erase(p1a.find(y));
				p1d.insert(y);
				flag = 1;
			}

			print(p1a);
			print(p1d);

			chefina.push_back(cfsum-csum);
			if(p2a.size() != 0 && p1d.size() != 0)
			{
				auto end = p1d.end();
				auto start = p2a.begin();
				end--;
				int x = *end;
				int y = *start;
				p1d.erase(p1d.find(x));
				csum -= x;
				p2a.erase(p2a.find(y));
				p2d.insert(y);
				flag = 1;
			}

		// 	print(p1a);
		// print(p1d);
		// print(p2a);
		// print(p2d);

			cout << "\n";
			if(flag == 0)
				break;
		}

		for(i=0; i<chef.size(); i++)
			cout << chef[i] << " ";
		cout << "\n";

		for(i=0; i<chefina.size(); i++)
			cout << chefina[i] << " ";
		cout << "\n";
	}
}