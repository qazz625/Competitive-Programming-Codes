#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, b, k, j, i, x, y;
	cin >> n >> a >> b >> k;
	int arr[n];

	for(i=0; i<n; i++)
		cin >> arr[i];

	double arr2[n];
	for(i=0; i<n; i++)
		if(arr[i]%(a+b) == 0)
			arr2[i] = a+b;
		else
			arr2[i] = (double)(arr[i]%(a+b));

	for(i=0; i<n; i++)
		arr2[i] = ceil(arr2[i]/a);

	sort(arr2, arr2+n);

	int count = 0, ind=0, lol=0;
	while(ind<n)
	{
		if(count + arr2[ind]-1 > k)
			break;
		count += arr2[ind]-1;
		ind++;
	}
	cout << ind << "\n";
}