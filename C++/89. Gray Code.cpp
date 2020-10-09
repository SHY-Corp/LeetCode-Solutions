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
