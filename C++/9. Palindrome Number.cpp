/*To determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.*/


class Solution {
public:
    bool isPalindrome(int x) {
    if(x<0)    // to check whether x is negative
    return false;
    else       // for positive x values
    {
        vector<int> a; // declaration of vector a
        while(x!=0)     // start of loop to get digits of x
        {
            a.push_back(x%10);
            x=x/10;
        }
        int c=1;
        int n = a.size();
        for(int i=0;i<n/2;i++) // start of loop
        {
            if(a[i]!=a[n-i-1])
            {
                c=0;
                break;        // breaks from the loop when x is not palindrome
            }
        }

        if(c==0)
            return false;
        else
            return true;    
    }
  }
};
