class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxcandies=0;
        vector <bool> bmap(candies.size());
        int n=candies.size();
        for(int i=0;i<n;++i)
        {
            maxcandies=max(maxcandies,candies[i]);
        }
        for(int i=0;i<n;++i)
        {
            bmap[i]=(maxcandies-extraCandies <= candies[i]);
        }
        return bmap;
    }
};
