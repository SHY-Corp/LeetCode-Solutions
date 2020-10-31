// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

class Solution {
public:
    int find_gcd(int a, int b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
    }
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) return points.size();

        int res = 0;

        for (int i1 = 0; i1 < points.size()-1; ++i1) {
            int duplicate = 0;
            unordered_map<string,int> mydict;
            for (int i2 = i1+1; i2 < points.size(); ++i2) {

                int dx = points[i1][0] - points[i2][0];
                int dy = points[i1][1] - points[i2][1];

                if (dx == 0 && dy == 0) ++duplicate;
                else if (dx == 0) ++mydict["v"];
                else if (dy == 0) ++mydict["h"];
                else {
					int temp = abs(find_gcd(dy,dx));
                    if (dy < 0) temp *= -1;
                    ++mydict[to_string(dy/temp)+to_string(dx/temp)];
                }
            }
            
            res = max(res,duplicate);
            for (auto i : mydict)
                res = max(res,i.second+duplicate);
        }
            
        return res + 1;
    }
};