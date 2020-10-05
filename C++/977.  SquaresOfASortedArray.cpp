#include <bits/stdc++.h>
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len=A.size();
        vector<int> B;
        for(int i=0;i<len;i++){
            B.push_back(A[i]*A[i]);
        }
        sort(B.begin(),B.end());
        return B;
    }
};
