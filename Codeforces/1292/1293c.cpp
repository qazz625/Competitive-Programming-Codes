#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int n, q, i, j, k, x, y;
	cin >> n >> q;
	set<vector<vector<int>>> svp;
	set<vector<int>> block;
	while(q--)
	{
		cin >> x >> y;
		vector<int> temp;
		temp.push_back(x);
		temp.push_back(y);
	

		vector<int> temp1;
		if(x == 1)
		{
			temp1.push_back(2);
			temp1.push_back(y);
		}
		else
		{
			temp1.push_back(1);
			temp1.push_back(y);
		}

		vector<int> temp2, temp3;
		if(x == 1)
		{
			temp2.push_back(2);
			temp2.push_back(y+1);
			temp3.push_back(2);
			temp3.push_back(y-1);
		}
		else
		{
			temp2.push_back(1);
			temp2.push_back(y+1);
			temp3.push_back(1);
			temp3.push_back(y-1);
		}
		if(block.find(temp) == block.end())
		{
			block.insert(temp);
			// print(temp1);
			// print(temp2);
			// print(temp3);

			if(block.find(temp1) != block.end())
			{
				vector<vector<int>> vv;
				vv.push_back(temp);
				vv.push_back(temp1);
				svp.insert(vv);
			}
			if(block.find(temp2) != block.end())
			{
				vector<vector<int>> vv;
				vv.push_back(temp);
				vv.push_back(temp2);
				svp.insert(vv);
			}
			if(block.find(temp3) != block.end())
			{
				vector<vector<int>> vv;
				vv.push_back(temp);
				vv.push_back(temp3);
				svp.insert(vv);
			}

		}
		else
		{
			block.erase(block.find(temp));


			vector<vector<int>> v1, v2, v3, v4, v5, v6;
			v1.push_back(temp); v1.push_back(temp1);
			v4.push_back(temp1); v4.push_back(temp);
			if(temp2[1]<= n)
			{
				v2.push_back(temp);
				v2.push_back(temp2);
				v5.push_back(temp2);
				v5.push_back(temp);
			}
			if(temp3[1] >= 1)
			{
				v3.push_back(temp);
				v3.push_back(temp3);
				v6.push_back(temp3);
				v6.push_back(temp);
			}
			if(svp.find(v1) != svp.end())
			{
				svp.erase(svp.find(v1));
			}
			if(svp.find(v2) != svp.end())
			{
				svp.erase(svp.find(v2));
			}
			if(svp.find(v3) != svp.end())
			{
				svp.erase(svp.find(v3));
			}
			if(svp.find(v4) != svp.end())
			{
				svp.erase(svp.find(v4));
			}
			if(svp.find(v5) != svp.end())
			{
				svp.erase(svp.find(v5));
			}
			if(svp.find(v6) != svp.end())
			{
				svp.erase(svp.find(v6));
			}

		}

		if(svp.size() == 0)
			cout << "Yes\n";
		else
			cout << "No\n";

	}
}