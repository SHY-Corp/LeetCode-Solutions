/*
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, 
print the sequence of gray code. A gray code sequence must begin with 0.

Example :
Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(pow(2,n));
        ans[0] = 0;
        for(int i = 1;i <= n;i++){
            ans[pow(2,i)-1] = pow(2,i-1);
        }
        
        for(int i = 0;i <pow(2,n);i++){
            if(pow(2,(int)log2(i+1)) != i+1){
                // 2, 1 3
                int ff = 0;
                ff |= 1<<((int)log2(i));
                int mid = pow(2,(int)log2(i));
                int diff = i - mid;
                int ind = mid - diff-1;
                
                ff |= ans[ind];
                ans[i] = ff;
            }
        }
        return ans;
    }
};
