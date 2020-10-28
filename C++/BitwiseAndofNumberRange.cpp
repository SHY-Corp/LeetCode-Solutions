
#include<bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 


int msbPos(ll n) 
{ 
	int msb_p = -1; 
	while (n) 
	{ 
		n = n>>1; 
		msb_p++; 
	} 
	return msb_p; 
} 

ll andOperator(ll x, ll y) 
{ 
	ll res = 0; 

	while (x && y) 
	{ 
		int msb_p1 = msbPos(x); 
		int msb_p2 = msbPos(y); 

		if (msb_p1 != msb_p2) 
			break; 

		ll msb_val = (1 << msb_p1); 
		res = res + msb_val; 

		x = x - msb_val; 
		y = y - msb_val; 
	} 

	return res; 
} 

// Driver code 
int main() 
{ 
	ll x = 10, y = 15; 
	cout << andOperator(x, y); 
	return 0; 
} 
