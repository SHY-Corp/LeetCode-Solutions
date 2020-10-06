class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //sorting the intervals on the basis of their starting points 
        sort(intervals.begin(), intervals.end());
        // count will store the number of redundant intervals 
        int count = 0;
        vector<int> curr = {-1, -1};
        for(int i = 0; i < intervals.size(); i++)
        {
            /*
                Three cases now:
                    1. intervals[i] lies completely inside curr => count++
                    2. curr lies completely inside intervals[i] => update curr and count++
                    3. intervals[i] and curr overlap partially  => update curr
            */
            if(intervals[i][0] >= curr[0] && intervals[i][1] <= curr[1]) {
                count++;
            }
            else if(intervals[i][0] <= curr[0] && intervals[i][1] >= curr[1]) {
                count++;
                curr = {intervals[i][0], intervals[i][1]};
            }
            else {
                curr = {intervals[i][0], intervals[i][1]};
            }
        }
        // We have to return the number of non-redundant intervals
        return intervals.size() - count;   
    }
};