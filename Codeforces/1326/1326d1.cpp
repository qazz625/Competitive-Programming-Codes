#include<bits/stdc++.h>
using namespace std;

void findLongestPalindromicString(string &text) 
{ 
	int N = text.size();
	if(N == 0) 
		return; 
	N = 2*N + 1; //Position count 
	int L[N]; //LPS Length Array 
	L[0] = 0; 
	L[1] = 1; 
	int C = 1; //centerPosition 
	int R = 2; //centerRightPosition 
	int i = 0; //currentRightPosition 
	int iMirror; //currentLeftPosition 
	int maxLPSLength = 0; 
	int maxLPSCenterPosition = 0; 
	int start = -1; 
	int end = -1; 
	int diff = -1; 
	
	for (i = 2; i < N; i++) 
	{ 
		iMirror = 2*C-i; 
		L[i] = 0; 
		diff = R - i; 
		if(diff > 0) 
			L[i] = min(L[iMirror], diff); 

		while ( ((i + L[i]) < N && (i - L[i]) > 0) && 
			( ((i + L[i] + 1) % 2 == 0) || 
			(text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] ))) 
		{ 
			L[i]++; 
		} 

		if(L[i] > maxLPSLength) // Track maxLPSLength 
		{ 
			maxLPSLength = L[i]; 
			maxLPSCenterPosition = i; 
		} 

		if (i + L[i] > R) 
		{ 
			C = i; 
			R = i + L[i]; 
		} 

	} 

	start = (maxLPSCenterPosition - maxLPSLength)/2; 
	end = start + maxLPSLength - 1; 
	for(i=start; i<=end; i++) 
		printf("%c", text[i]); 
	printf("\n"); 
} 

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		int i, j, k, x, y;
		cin >> s;
		int n = s.size();
	}
}