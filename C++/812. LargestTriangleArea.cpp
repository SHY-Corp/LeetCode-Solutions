/*
Problem 812 - Largest Triangle Area

You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.
*/

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = -1;
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                for(int k=0; k<points.size(); k++){
                    double area = triangleArea(points[i], points[j], points[k]); //calculation of triangle area with 'Heron's formula'
                    if(area > maxArea) maxArea = area;  //if the 3 points form a triangle with a larger area: update variable to be returned
                }
            }
        }
        return maxArea;
    }

    double triangleArea(vector<int> p1, vector<int> p2, vector<int> p3){
        double l1 = sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
        double l2 = sqrt(pow(p2[0] - p3[0], 2) + pow(p2[1] - p3[1], 2));
        double l3 = sqrt(pow(p3[0] - p1[0], 2) + pow(p3[1] - p1[1], 2));
        double semiPerimeter = (l1+l2+l3)/2;
        //Heron's formula
        return sqrt(semiPerimeter * (semiPerimeter - l1) * (semiPerimeter - l2) * (semiPerimeter - l3));

    }
};