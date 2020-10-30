// Problem - 1610. Maximum Number of Visible Points

/*
Problem statement -
You are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] both denote integral coordinates on the X-Y plane.

Initially, you are facing directly east from your position. You cannot move from your position, but you can rotate. 
In other words, posx and posy cannot be changed. Your field of view in degrees is represented by angle, determining how wide you can see from any given view direction. 
Let d be the amount in degrees that you rotate counterclockwise. Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].
You can see some set of points if, for each point, the angle formed by the point, your position, and the immediate east direction from your position is in your field of view.
There can be multiple points at one coordinate. There may be points at your location, and you can always see these points regardless of your rotation. Points do not obstruct your vision to other points.
Return the maximum number of points you can see.

Refer question on leetcode for visualization
*/

/*
Constraints - 
1. 1 <= points.length <= 105
2. points[i].length == 2
3. location.length == 2
4. 0 <= angle < 360
5. 0 <= posx, posy, xi, yi <= 109
*/

/*
Example 1:
Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
Output: 3
Explanation: The shaded region represents your field of view. 
All points can be made visible in your field of view, including [3,3] even though [2,2] is in front and in the same line of sight.

Example 2:
Input: points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
Output: 4
Explanation: All points can be made visible in your field of view, including the one at your location.

Example 3:
Input: points = [[1,0],[2,1]], angle = 13, location = [1,1]
Output: 1
Explanation: You can only see one of the two points, as shown above.

*/

//Solution
/*
Idea -
1. Find the angle between each point and your location (against the x axis)
2. Duplicate entire array and append it to the end. Then increase angle by 360 for the appended portion - this is since we're working with a cyclic array. 
Once you reach the end of the array, you want to continue comparing those values with the values at the beginning of the array.
3. Use a sliding window to find the max that fit within the given degree
4. Special case: If the given point is the same as location (for eg. both are [1, 1]) then count that separately - since there is no way to know the angle if the points overlap
*/
#define PI 3.14159265
#define MARGIN 1e-9

class Solution {
public:
    double get_angle(int x_diff, int y_diff) {
        return atan2(y_diff, x_diff) * 180 / PI;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int i, j, n = points.size(), common = 0;
        vector<double> vals;
        for(i=0; i<n; i++) {
            int x = points[i][0] - location[0];
            int y = points[i][1] - location[1];
            if(x == 0 && y == 0) {
                common++;
            }
            else {
                double A = get_angle(x, y);
                if(A < 0) A += 360;
                vals.emplace_back(A);
            }
        }

        sort(vals.begin(), vals.end());
        vector<double> a = vals;
        a.insert(a.end(), vals.begin(), vals.end());
        for(i=vals.size(); i<a.size(); i++)
            a[i] += 360;
        int ret = 0;
        for(i=0, j=0; i<a.size(); i++) {
            while(j < a.size() && (a[j]-a[i]<=angle + MARGIN))
                  j++;
            ret = max(ret, j - i);
        }
        return ret + common;
    }
};
