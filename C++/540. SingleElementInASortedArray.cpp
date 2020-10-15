// The idea is that by, cumulatively, XORing all elements in an array, the result is the single element in the array.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int singleNonDuplicate(vector<int> & nums){
        int answer = 0;
        for(auto e : nums) answer ^= e;
        return answer;
    }
};
