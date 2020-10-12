/*

A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).

Given a starting point (sx, sy) and a target point (tx, ty), return True if and only if a sequence of moves exists to transform the point (sx, sy) to (tx, ty). Otherwise, return False.

Examples:
Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: True
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: False

Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: True

 */
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {

        // if the initial coordinates are equal then the points can be reached
        if (tx == ty) return sx == sy && sx == tx;

        //
        while (sx != tx || sy != ty) {

            // this cannot be possible if the points can be reached , hence returning false
            if (tx < sx || ty < sy) return false;

            // subtracting and traversing ahead
            if (tx > ty) tx -= max((tx-sx)/ty, 1) * ty;
            else         ty -= max((ty-sy)/tx, 1) * tx;
        }

        // if the above loop completed , without returning , that means that the points can be reached. Hence , we return true
        return true;

    }
};