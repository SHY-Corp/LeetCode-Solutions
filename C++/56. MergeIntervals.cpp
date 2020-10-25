/*
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 *
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 *
 * Example 2:
 *
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 */
 
 //------------------------------------Solution-----------------------------------
 /*
  * In this, we are first sorting the intervals as these are not in sorted order.
  * We are taking the first interval out and keeping its value in lower and upper variable (and denoting this interval as previous interval)
  * , so that we can use it to compare next preceding intervals.   
  * For each consecutive intervals, we will check if the starting of the current interval is smaller than the end of the previous interval and the end value
  * of the previous interval smaller than the end value of the current interval. Then, we will update the end value of the previous interval with current interval. 
  * If the end of the previous is smaller then the start of the current, then we insert the previous value and update the current interval's value
  * with previous one i.e current interval value will become the lower and upper.
  *
  */
  class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<vector<int>> solution;
        if (size <= 0)
            return solution;
        sort(intervals.begin(), intervals.end());
        int lower =  intervals[0][0], upper = intervals[0][1];
        for (int i=1; i<size; i++) {
            vector<int> interval = intervals[i];
            if (interval[0] <=  upper && upper < interval[1]) {
                upper = interval[1];
            }
            else if(upper < interval[0]) {
                solution.push_back({lower, upper});
                lower = interval[0];
                upper = interval[1];
            }
        }
        solution.push_back({lower, upper});
        return solution;
    }
};
