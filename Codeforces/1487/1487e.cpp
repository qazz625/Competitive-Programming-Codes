#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif

int arr1[200000], arr2[200000], arr3[200000], arr4[200000];
int newarr2[200000], newarr3[200000];
vector<int> n2n1[200000], n3n4[200000], n3n2[200000];

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;

	for(int i=0; i<n1; i++)
		cin >> arr1[i];
	for(int i=0; i<n2; i++)
		cin >> arr2[i];
	for(int i=0; i<n3; i++)
		cin >> arr3[i];
	for(int i=0; i<n4; i++)
		cin >> arr4[i];

	set<pair<int, int>> s4;
	for(int i=0; i<n4; i++)
		s4.insert({arr4[i], i});

	set<pair<int, int>> s1;
	for(int i=0; i<n1; i++)
		s1.insert({arr1[i], i});

	int m1, m2, m3;
	cin >> m1;
	for(int i=0; i<m1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		n2n1[v].push_back(u);
	}

	cin >> m2;
	for(int i=0; i<m2; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		n3n2[v].push_back(u);
	}

	cin >> m3;
	for(int i=0; i<m3; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		n3n4[u].push_back(v);
	}

	for(int i=0; i<n2; i++){
		for(auto x: n2n1[i])
			s1.erase({arr1[x], x});

		if(s1.size() == 0)
			newarr2[i] = 1e17;
		else
			newarr2[i] = arr2[i] + (*s1.begin()).first;

		for(auto x: n2n1[i])
			s1.insert({arr1[x], x});
	}

	set<pair<int, int>> s2;
	for(int i=0; i<n2; i++)
		s2.insert({newarr2[i], i});

	for(int i=0; i<n3; i++){
		for(auto x: n3n4[i])
			s4.erase({arr4[x], x});
		for(auto x: n3n2[i])
			s2.erase({newarr2[x], x});

		if(s4.size() == 0 || s2.size() == 0)
			newarr3[i] = 1e17;
		else
			newarr3[i] = arr3[i] + (*s4.begin()).first + (*s2.begin()).first;

		for(auto x: n3n4[i])
			s4.insert({arr4[x], x});
		for(auto x: n3n2[i])
			s2.insert({newarr2[x], x});
	}

	int ans = 1e18;
	for(int i=0; i<n3; i++)
		ans = min(ans, newarr3[i]);

	if(ans > 1e16)
		cout << "-1\n";
	else
		cout << ans << "\n";
}
