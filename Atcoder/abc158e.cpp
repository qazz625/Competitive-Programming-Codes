#include<bits/stdc++.h>
using namespace std;

int findSubarraySum(vector<int> &arr, int n, int sum) 
{ 
	// STL map to store number of subarrays 
	// starting from index zero having 
	// particular value of sum. 
	unordered_map<int, int> prevSum; 

	int res = 0; 

	// Sum of elements so far. 
	int currsum = 0; 

	for (int i = 0; i < n; i++) { 

		// Add current element to sum so far. 
		currsum += arr[i]; 

		// If currsum is equal to desired sum, 
		// then a new subarray is found. So 
		// increase count of subarrays. 
		if (currsum == sum) 
			res++;		 

		// currsum exceeds given sum by currsum 
		// - sum. Find number of subarrays having 
		// this sum and exclude those subarrays 
		// from currsum by increasing count by 
		// same amount. 
		if (prevSum.find(currsum - sum) != 
								prevSum.end()) 
			res += (prevSum[currsum - sum]); 
		

		// Add currsum value to count of 
		// different values of sum. 
		prevSum[currsum]++; 
	} 

	return res; 
} 

int main()
{
	int n, p, i, j, k, x, y;
	string s;
	cin >> n >> p;
	cin >> s;
	int power = 1;
	vector<int> v;
	for(i=n-1; i>=0; i--)
	{
		x = s[i]-'0';
		v.push_back((x*power)%p);
		power *= 10;
		power %= p;
	}

	reverse(v.begin(), v.end());



	// for(i=0; i<v.size(); i++)
	// 	cout << v[i] << " ";
	// cout << "\n";

	int ans=0;
	for(i=0; i<100; i++)
	{
		ans += findSubarraySum(v, v.size(), i*p);
	}
	cout << ans << "\n";
}
