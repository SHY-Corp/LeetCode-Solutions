class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();

        if(n==2)
            return true;
        /*
           A straight line has one slope! If any 2 points on a straight line have a slope equal to the
           slope of the given line, they form a straight line.

           Slope of (x1, y1) and (x2, y2) = (y2-y1)/(x2-x1)
           If the slope of (xi, yi) is equal to the above slope, return true, else return false.
        */
        int x1=coordinates[1][0];
        int y1=coordinates[1][1];
        int x2=coordinates[0][0];
        int y2=coordinates[0][1];

        int y_diff = y2-y1;
        int x_diff = x2-x1;

        for(int i=2; i<n; i++)
        {
            int x = coordinates[i][0] - x2;
            int y = coordinates[i][1] - y2;

            // m1(y_diff/x_diff) = m2(y/x), checking the slopes
            if(x * y_diff != x_diff * y)
                return false;
        }
        return true;
    }
};
