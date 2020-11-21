// problem - 593. Valid Square

/*
    Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points 
    construct a square.

    The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

    A valid square has four equal sides with positive length and four equal angles (90-degree angles).
*/

class Solution {
public:
    // returns euclidean distance between 2 points
    float distance(vector<int>& p1, vector<int>& p2) {
        float x = pow(p1[0] - p2[0], 2);
        float y = pow(p1[1] - p2[1], 2);
        return sqrt(x+y);
    }
     
    // returns the slope of 2 points
    float slope(vector<int>& p1, vector<int>& p2) {
        // if denominator == 0 returning some number close to (infinity)
        if((p2[0] - p1[0]) == 0) return 99999999;
        return (p2[1] - p1[1])/(p2[0] - p1[0]);
    }
    
    // to check if 3 points are collinear or not
    bool collinear(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
        float s1 = slope(p1, p2);
        float s2 = slope(p1, p3);
        float s3 = slope(p2, p3);
        
        if(s1 == s2 && s1 == s3 && s2 == s3) return true;
        else return false;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // if any 2 points are the same then square cannot be formed
        if((p1[0] == p2[0] && p1[1] == p2[1]) ||
           (p1[0] == p3[0] && p1[1] == p3[1]) ||
           (p1[0] == p4[0] && p1[1] == p4[1]) ||
           (p2[0] == p3[0] && p2[1] == p3[1]) ||
           (p2[0] == p4[0] && p2[1] == p4[1]) ||
           (p4[0] == p3[0] && p4[1] == p3[1])) return false;
        
        // distance between p1 and others
        float s1 = distance(p1, p2);
        float s2 = distance(p1, p3);
        float s3 = distance(p1, p4);
        
        if(s1 == s2) {
            float s4 = distance(p4, p2);
            float s5 = distance(p4, p3);
            float s6 = distance(p2, p3);
            // side, diagonal and collinearity check 
            if(s4 == s5 && s6 == s3 && !collinear(p1, p2, p3)) return true;
        } else if(s1 == s3) {
            float s4 = distance(p3, p2);
            float s5 = distance(p3, p4);
            float s6 = distance(p2, p4);
            // side, diagonal and collinearity check 
            if(s4 == s5 && s6 == s2 && !collinear(p1, p2, p4)) return true;
        } else if(s2 == s3) {
            float s4 = distance(p2, p3);
            float s5 = distance(p2, p4);
            float s6 = distance(p4, p3);
            // side, diagonal and collinearity check 
            if(s4 == s5 && s6 == s1 && !collinear(p1, p4, p3)) return true;
        }
        
        return false;
    }
};

// Time Complexity = O(√n) [√n complexity for sqrt()]
// Space Complexity = O(1)