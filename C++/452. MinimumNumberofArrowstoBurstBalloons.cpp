/*
    Problem Statement:
    There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.

    An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

    Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be shot to burst all balloons.
    
    Problem Link:
    https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

    Approach:
    Sort the given points and find the segments that are not intesecting.
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int> p1,vector<int>p2){
            return p1[1]<p2[1];
        });
        int n = points.size();
        if(!n) return 0;
        int currEnd = points[0][1];
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(currEnd < points[i][0]){
                cnt++;
                currEnd = points[i][1];
            }
        }
        return cnt;
    }
};