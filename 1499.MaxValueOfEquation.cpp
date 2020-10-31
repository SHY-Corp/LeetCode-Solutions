/*Find the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length. It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.*/
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // Maintain a sliding window map of left and right.
        map<int, int> sw;
        int left = 0, right = 0;
        int n = points.size();
        sw[points[left][0] + points[left][1]]++;
        int ans = -3E8;
        while (left < n) {
            // Include right until full.
            while (right + 1 < n && points[right + 1][0] <= k + points[left][0]) {
                ++right;
                sw[points[right][0] + points[right][1]]++;
            }
            // Exclude left.
            --sw[points[left][0] + points[left][1]];
            if (sw[points[left][0] + points[left][1]] == 0) {
                sw.erase(points[left][0] + points[left][1]);
            }
            // Retrieve the top maximum.
            auto it = sw.rbegin();
            if (it != sw.rend()) {
                ans = max(ans, it->first - (points[left][0] - points[left][1]));
            }
            ++left;
        }
        return ans;
    }
};
