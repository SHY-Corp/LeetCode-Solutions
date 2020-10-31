//******************||||      AUTHOR: SK ABDUR RAHAMAN HOSSAIN       ||||*********************************||
//******************||||      INSTITUTION : JGEC                     ||||*********************************||

#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
Algorithm:
1.Take care of some base cases, i.e when the given number is 0 or 1.
2.Create some variables, lowerbound l = 0, upperbound r = n, where n is the given number, mid and ans to store the answer.
3.Run a loop until l <= r , the search space vanishes
4.Check if the square of mid (mid = (l + r)/2 ) is less than or equal to n, If yes then search for a larger value in second half oF search space, i.e l = mid + 1, update ans = mid
5.Else if the square of mid is less than n then search for a smaller value in first half oF search space, i.e r = mid – 1
6.Print the value of answer ( ans)
*/

// Returns floor of square root of x          
ll floorSqrt(ll x)  
{      // Base cases 
    if (x == 0 || x == 1)  
       return x; 
   // Do Binary Search for floor(sqrt(x)) 
    ll start = 1, end = x, ans;    
    while (start <= end)  
    {         
        ll mid = (start + end) / 2; 
  
            if (mid*mid == x) 
            return mid; 
   
   // Since we need floor, we update answer when mid*mid is  
        // smaller than x, and move closer to sqrt(x) 
        
          if (mid*mid < x)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else //sqrt lies in the left half
            end = mid-1;         
    } 
    return ans; 
} 
int main() {
	ll n;
	cin>>n;//taking input
	cout<<floorSqrt(n);//output the sqrt of n
	
	return 0;
}
