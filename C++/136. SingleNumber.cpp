// We have to find a unique number out of the given numbers as that number will only occur once

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int>s;
        int sumSet=0;
        int sumNo = 0;
        for(auto x:nums){
            if(s.find(x)==s.end()){
                sumSet+=x;
                s.insert(x);
            }
                sumNo+=x;
        }
        return 2*sumSet - sumNo;
    }
};