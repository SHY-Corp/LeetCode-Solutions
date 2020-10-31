/* find a co ordinate thats efficient and equidistant and return the min possible sum of distances*/

class Solution {
public:
    double dist(double x, double y, vector<vector<int>>& positions){
        double ans =0.0;
        for(auto p:positions){
            ans += sqrt((p[0]-x)*(p[0]-x) + (p[1]-y)*(p[1]-y));
        }
        return ans;
    }
    double getMinDistSum(vector<vector<int>>& positions) {
        
        double x=0.0, y=0.0;
        for(auto p:positions){
            x += p[0];
            y += p[1];
        }
        int n = positions.size();
        x/=n;
        y/=n;
        double step = 10;
        double dis = dist(x,y, positions);
        vector<vector<int>> dir{{1,0}, {-1,0}, {0,1}, {0, -1}};
        while(step > 0.0000001){
            vector<int> move = {0,0};
            for(auto d:dir){
                double d1 = dist(x+step*d[0], y + step*d[1], positions);
                if(d1 < dis){
                    move = {d[0], d[1]};
                    dis = d1;
                    break;
                }
            }
            x+=step*move[0];
            y+=step*move[1];
            if(move[0] == 0 && move[1] == 0)
                step *= 0.1;
        }
        
        return dist(x,y, positions);
    }
};
