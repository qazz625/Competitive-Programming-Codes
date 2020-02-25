    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
    	int count = 0, mod = 1000000007, i, j, k;
    	vector<vector<int>> v;
     
    	for(i=1; i<20001; i++)
    	{
    		for(j=i; j<20001; j+=i)
    		{
    			for(k=j; k<20001; k+=j)
    			{
    				vector<int> temp;
    				temp.push_back(i+j+k);
    				temp.push_back(i);
    				temp.push_back(j);
    				temp.push_back(k);
    				v.push_back(temp);
    			}
    		}
    	}
    	cout << v.size() << "\n";
     
    	// sort(v.begin(), v.end());
     
    	int t;
    	cin>> t;
    	while(t--)
    	{
    		int a, b, c;
    		cin >> a >> b >> c;
    		int mi = 9999999, ind;
    		for(i=0; i<v.size(); i++)
    		{
    			int cost = abs(v[i][1]-a) + abs(v[i][2]-b) + abs(v[i][3]-c);
    			if(cost < mi)
    			{
    				mi = cost;
    				ind = i;
    			}
    		}
     
    		cout << mi << "\n";
    		cout << v[ind][1] << " " << v[ind][2] << " " << v[ind][3] << "\n";
    	}
     
    }