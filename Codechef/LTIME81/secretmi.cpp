#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int i, j, k, x, y, u ,v, w;
        int n, m, l;
        cin >> n >> m >> l;
        int arr[l];
        for(i=0; i<l; i++)
            cin >> arr[i];
        int d[n][n];
        int ori[n][n];

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {
                if(i == j)
                    d[i][j] = 0;
                else
                    d[i][j] = 999999999;
            }

        for(i=0; i<m; i++)
        {
            cin >> u >> v >> w;
            u--; v--;
            d[u][v] = w;
            d[v][u] = w;
            ori[u][v] = w;
            ori[v][u] = w;
        }


        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
                }
            }
        }

        int ans=1;
        for(i=0; i<l-1; i++)
        {
            if(d[arr[i]-1][arr[i+1]-1] != ori[arr[i]-1][arr[i+1]-1])
            {
                ans = -1;
                break;
            }
        }

        if(ans == -1)
        {
            cout << "-1\n";
            continue;
        }

        int ind=0;
        while(ind != l)
        {
            int su=0;
            int end = ind+1;
            while(true)
            {
                su += ori[arr[end-1]-1][arr[end]-1];
                if(end == l-1 && d[arr[ind]-1][arr[end]-1] == su)
                {
                    ind = l;
                    break;
                }
                if(end < l && d[arr[ind]-1][arr[end]-1] == su)
                    end++;
                else
                {
                    ind = end-1;
                    break;
                }

            }
            ans++;
        }

        cout << ans << "\n";

    }
}