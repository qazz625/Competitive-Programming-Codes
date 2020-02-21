#include <bits/stdc++.h> 
using namespace std; 

int power(int x, unsigned int y) 
{ 
    int res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}
  
 vector<int> primeFactors(int n)  
{  
    vector<int> v;
    while (n % 2 == 0)  
    {  
        v.push_back(2); 
        n = n/2;  
    }  

    for (int i = 3; i*i <= n; i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            v.push_back(i);
            n = n/i;  
        }  
    }  
    if (n > 2)  
        v.push_back(n);
    return v ;
}  
  
/* Driver code */
int main()  
{  
    int t;
    cin >> t;
    while(t--)
    {
        int i, j, n;
        cin >> n;
        vector<int> v = primeFactors(n);
        if(v.size() <= 2)
            cout << "NO\n";
        else
        {
            // for(i=0; i<v.size(); i++)
            //     cout << v[i] << " ";
            // cout << "\n";
            map<int, int> ma;
            for(i=0; i<v.size(); i++)
                ma[v[i]] += 1;
            
            // cout << n << "\n";
            // for(auto x:ma)
            //     cout << x.first << " " << x.second << "\n";
            if(ma.size() == 1)
            {
                
                int flag, lol, num;
                for(auto x: ma)
                {
                    lol = x.second;
                    num = x.first;
                    if(x.second >= 6)
                        flag =0;
                    else
                        flag = 1;
                }
                if(flag == 1)
                    cout << "NO\n";
                else
                {
                    cout << "YES\n";
                    cout << num << " " << num*num << " " <<  power(num, lol-3) << "\n";
                }
            }

            else if(ma.size() == 2)
            {
                int flag, count=0, lol1, lol2, num1, num2;
                for(auto x: ma)
                {
                    if(count == 0)
                    {
                        lol1 = x.second;
                        num1 = x.first;
                    }
                    else
                    {
                        lol2 = x.second;
                        num2 = x.first;
                    }
                    count += 1;
                }

                if((lol1 >= 2 && lol2 >= 2) || (lol1 >= 3) || (lol2 >= 3))
                {
                    cout << "YES\n";
                    cout << num1 << " " << num2 << " " << power(num1, lol1-1)*power(num2, lol2-1) << "\n";
                }
                else
                {
                    cout << "NO\n";
                }

            }
            else
            {
                // cout << "LOL";
                int count=0, prod = 1, one, two;
                cout << "YES\n";
                for(auto x: ma)
                {
                    if(count == 0)
                        one = power(x.first, x.second);
                    if(count == 1)
                        two = power(x.first, x.second);
                    if(count > 1)
                        prod *= power(x.first, x.second);
                    count += 1;

                    
                }
                cout << one << " " << two << " " << prod << "\n";


                
            }
        }

    }
}  