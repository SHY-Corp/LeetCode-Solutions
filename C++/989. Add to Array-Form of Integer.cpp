/*
https://leetcode.com/problems/add-to-array-form-of-integer/

For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size()-1, x, y;
        vector<int>ret;
        int carry(0); 
        for(int carry = 0; n >= 0  || K || carry; ){
        	if(n >= 0){
        		x = A[n];
        		n--;
        	}
        	else
        		x = 0;
            int ele = x+K%10+carry;
            K /= 10;
            carry = ele/10;
            ret.push_back(ele%10);
            
        }
        reverse(ret.begin(), ret.end());
        
        return ret; 
    }
};