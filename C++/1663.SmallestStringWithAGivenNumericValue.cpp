class Solution {
public:
    string getSmallestString(int n, int k) {

        //initialising a string of length n and filling it with 'a'
        string result(n, 'a');

        //numeric value of 'a' = 1, the numeric value of the resulting string will become k-n as we have
        //filled all with 'a', so k = k - (1*n);
        k = k-n;

        while(k>0)
        {
            //for iterating each index from the end
            n--;
            //changing the last value from 'a' to 'z' or k, whichever is minimum
            result[n] = result[n] + min(25,k);
            //decrementing k by the value to which 'a' was changed
            k = k - min(25,k);
        }

        return result;
    }
};

/*
You can checkout this link for understanding the problem through an example:
https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/discuss/1871662/JavaC%2B%2B-Easiest-Possible-Exaplained!!

*/
