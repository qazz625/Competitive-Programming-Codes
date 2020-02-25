// C++ program to print the number of elements 
// greater than k in a subarray of range L-R. 
#include <bits/stdc++.h> 
using namespace std; 

int ANS=0;

// Structure which will store both 
// array elements and queries. 
struct node { 
	int pos; 
	int l; 
	int r; 
	int val; 
}; 

// Boolean comparator that will be used 
// for sorting the structural array. 
bool comp(node a, node b) 
{ 
	// If 2 values are equal the query will 
	// occur first then array element 
	if (a.val == b.val) 
		return a.l > b.l; 

	// Otherwise sorted in descending order. 
	return a.val > b.val; 
} 

// Updates the node of BIT array by adding 
// 1 to it and its ancestors. 
void update(int* BIT, int n, int idx) 
{ 
	while (idx <= n) { 
		BIT[idx]++; 
		idx += idx & (-idx); 
	} 
} 
// Returns the count of numbers of elements 
// present from starting till idx. 
int query(int* BIT, int idx) 
{ 
	int ans = 0; 
	while (idx) { 
		ans += BIT[idx]; 

		idx -= idx & (-idx); 
	} 
	return ans; 
} 

// Function to solve the queries offline 
void solveQuery(int arr[], int n, int QueryL[], 
				int QueryR[], int QueryK[], int q) 
{ 
	// create node to store the elements 
	// and the queries 
	node a[n + q + 1]; 
	// 1-based indexing. 

	// traverse for all array numbers 
	for (int i = 1; i <= n; ++i) { 
		a[i].val = arr[i - 1]; 
		a[i].pos = 0; 
		a[i].l = 0; 
		a[i].r = i; 
	} 

	// iterate for all queries 
	for (int i = n + 1; i <= n + q; ++i) { 
		a[i].pos = i - n; 
		a[i].val = QueryK[i - n - 1]; 
		a[i].l = QueryL[i - n - 1]; 
		a[i].r = QueryR[i - n - 1]; 
	} 

	// In-built sort function used to 
	// sort node array using comp function. 
	sort(a + 1, a + n + q + 1, comp); 

	// Binary Indexed tree with 
	// initially 0 at all places. 
	int BIT[n + 1]; 

	// initially 0 
	memset(BIT, 0, sizeof(BIT)); 

	// For storing answers for each query( 1-based indexing ). 
	int ans[q + 1]; 

	// traverse for numbers and query 
	for (int i = 1; i <= n + q; ++i) { 
		if (a[i].pos != 0) { 

			// call function to returns answer for each query 
			int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1); 

			// This will ensure that answer of each query 
			// are stored in order it was initially asked. 
			ans[a[i].pos] = cnt; 
		} 
		else { 
			// a[i].r contains the position of the 
			// element in the original array. 
			update(BIT, n, a[i].r); 
		} 
	} 
	// Output the answer array 
	for (int i = 1; i <= q; ++i) { 
		ANS += ans[i];
	} 
} 






// Returns the count of numbers of elements 
// present from starting till idx. 
int query2(int* BIT, int idx) 
{ 
	int ans = 0; 
	while (idx) { 
		ans += BIT[idx]; 

		idx -= idx & (-idx); 
	} 
	return ans; 
} 

// Function to solve the queries offline 
void solveQuery2(int arr[], int n, int QueryL[], 
				int QueryR[], int QueryK[], int q) 
{ 
	// create node to store the elements 
	// and the queries 
	node a[n + q + 1]; 
	// 1-based indexing. 

	// traverse for all array numbers 
	for (int i = 1; i <= n; ++i) { 
		a[i].val = arr[i - 1]; 
		a[i].pos = 0; 
		a[i].l = 0; 
		a[i].r = i; 
	} 

	// iterate for all queries 
	for (int i = n + 1; i <= n + q; ++i) { 
		a[i].pos = i - n; 
		a[i].val = QueryK[i - n - 1]; 
		a[i].l = QueryL[i - n - 1]; 
		a[i].r = QueryR[i - n - 1]; 
	} 

	// In-built sort function used to 
	// sort node array using comp function. 
	sort(a + 1, a + n + q + 1, comp); 

	// Binary Indexed tree with 
	// initially 0 at all places. 
	int BIT[n + 1]; 

	// initially 0 
	memset(BIT, 0, sizeof(BIT)); 

	// For storing answers for each query( 1-based indexing ). 
	int ans[q + 1]; 

	// traverse for numbers and query 
	for (int i = 1; i <= n + q; ++i) { 
		if (a[i].pos != 0) { 

			// call function to returns answer for each query 
			int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1); 

			// This will ensure that answer of each query 
			// are stored in order it was initially asked. 
			ans[a[i].pos] = cnt; 
		} 
		else { 
			// a[i].r contains the position of the 
			// element in the original array. 
			update(BIT, n, a[i].r); 
		} 
	} 
	// Output the answer array 
	for (int i = 1; i <= q; ++i) { 
		cout << ans[i] << endl; 
	} 
} 






int main()
{
	int n, i, j, k, x, y;
	cin >> n;
	vector<pair<int, int>> vp;
	for(i=0; i<n; i++)
	{
		pair<int, int> temp;
		cin >> x;
		temp.first = x;
		temp.second = 0;
		vp.push_back(temp);
	}
	for(i=0; i<n; i++)
	{
		cin >> x;
		vp[i].second = x;
	}

	sort(vp.begin(), vp.end());

	vector<pair<int, int>> pfx;
	vector<int> zeropfx;
	int neg=0, pos=0, zero=0;
	map<int, vector<int>> mp;
	map<int, vector<int>> mppfx;
	for(i=0; i<n; i++)
	{
		pair<int, int> temp;
		mp[vp[i].second].push_back(vp[i].first);
		if(vp[i].second < 0)
			neg++;
		else if(vp[i].second > 0)
			pos++;
		else
			zero++;
		temp.first = pos;
		temp.second = neg;
		pfx.push_back(temp);
		zeropfx.push_back(zero);
	}

	for(auto x: mp)
	{
		int su = 0;
		for(auto y: x.second)
		{
			su += y;
			mppfx[x.first].push_back(su);
		}
	}

	for(auto x: mp)
	{
		cout << x.first << ": ";
		for(auto y:x.second)
			cout << y << " ";
		cout << "\n";
	}

	cout << "\n";

	for(auto x: mppfx)
	{
		cout << x.first << ": ";
		for(auto y: x.second)
			cout << y << " ";
		cout << "\n";
	}

	int ans = 0;

	for(i=1; i<n-1; i++)
	{
		
	}


	int lol[n], lq1[n-1], rq1[n-1], kq1[n-1];
	int lq2[2*n-2], rq2[2*n-2], kq2[2*n-2];
	for(i=0; i<n; i++)
	{
		lol[i] = vp[i].second;
		// cout << lol[i] << "\n";
	}


	for(i=1, j=0; i<n-1; i++, j++)
	{
		// cout << "AA" << lol[i] << "\n";
		if(lol[i] >= 0)
		{
		// cout << vp[i].first << " " << vp[i].second << "\n";
			lq1[j] = i+2;
			rq1[j] = n;
			kq1[j] = lol[i];

		}
		else if(lol[i] < 0)
		{
			lq1[j] = 1;
			rq1[j] = i;
			kq1[j] = lol[i];
		}
	}
	// for(i=0; i<n-2; i++)
	// {
	// 	cout << lq1[i] << " " <<rq1[i] << " " << kq1[i] << "\n";
	// }
	solveQuery(lol, n, lq1, rq1, kq1, n-2);

	for(i=1, j=0; i<n-1; i++, j++)
	{
		// cout << "AA" << lol[i] << "\n";
		if(lol[i] >= 0)
		{
		// cout << vp[i].first << " " << vp[i].second << "\n";
			lq2[j] = 1;
			rq2[j] = i;
			kq2[j] = 0;

		}
		else if(lol[i] < 0)
		{
			lq2[j] = i+2;
			rq2[j] = n;
			kq2[j] = lol[i];
		}
	}


}