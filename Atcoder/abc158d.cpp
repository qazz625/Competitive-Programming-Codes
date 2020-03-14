#include<bits/stdc++.h>
using namespace std;

void printdq(deque<char> dq, int rev)
{
	int i;
	if(rev == 0)
	{

		for(auto it=dq.begin(); it!=dq.end(); it++)
			cout << *it;

		// for(i=0; i<dq.size(); i++)
		// 	cout << dq.front() << " ";
		// dq.pop_front();
	}
	else
	{
		reverse(dq.begin(), dq.end());
		for(auto it=dq.begin(); it!=dq.end(); it++)
			cout << *it;
	}
	cout << "\n";
}

int main()
{
	string s;
	cin >> s;
	deque<char> dq;
	for(int i=0; i<s.size(); i++)
	{
		dq.push_back(s[i]);
	}
	int i, j, k, x, y, q;
	cin >> q;
	int rev=0;
	while(q--)
	{
		int f, t;
		char c;
		cin >> t;


		if(t == 1)
			rev = rev^1;
		else
		{
			cin >> f >> c;
			if(f == 1 && rev == 0)
			{
				// printdq(dq, rev);
				// cout << "AA";
				dq.push_front(c);
				// printdq(dq, rev);
			}
			else if(f == 2 && rev == 0)
			{
				// cout << "BB";
				dq.push_back(c);
			}
			else if(f == 1 && rev == 1)
			{
				// cout << "DD";
				dq.push_back(c);
			}
			else
			{
				// cout << "EE";
				dq.push_front(c);
			}
		}

		

		
	}
	printdq(dq, rev);

}