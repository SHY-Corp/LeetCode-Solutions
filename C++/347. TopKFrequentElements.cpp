
/* PROBLEM : Given a non-empty array of integers, return the k most frequent elements.

APPROACH: Approached using a map data structure to count the frequency of each element.
*/




class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto x:nums) m[x]++;
        vector<pair<int,int>> v;
        for(auto x:m){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        int ct=0,pt=v.size()-1;
        while(ct<k && ct<v.size()){
            ans.push_back(v[pt].second);
            pt--;
            ct++;
        }
        return ans;
    }
};
