class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {

        //setting index as -1 initially
        int index=-1;
        int distance = INT_MAX;
        int manhattanDist;

        for(int i=0; i<points.size(); i++)
        {
            //calculating manhattan distance only if the points are valid
            if(points[i][0]==x || points[i][1]==y)
            {
                manhattanDist = abs(x-points[i][0]) + abs(y-points[i][1]);

                //updating distance with the smaller manhattan distance and initialising index with current i
                if(distance > manhattanDist)
                {
                    distance = manhattanDist;
                    index = i;
                }
            }
        }
        return index;
    }
};
