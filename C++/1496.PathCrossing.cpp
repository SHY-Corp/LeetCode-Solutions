/*Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.  */

/*Return True if the path crosses itself at any point, that is, if at any time you are on a location you've previously visited. Return False otherwise.*/
class Solution {
public:
    bool isPathCrossing(string path) {
        map<string, int> m;
        int x = 0, y = 0;
        m["00"]+=1;
        for(int i = 0; i < path.size(); i++){
            string temp = "";
            if(path[i]=='N') y+=1;
            else if(path[i]=='S') y-=1;
            else if(path[i]=='E') x+=1;
            else if(path[i]=='W') x-=1;
            temp = to_string(x);
            temp +=to_string(y);
            m[temp]+=1;
            if(m[temp] > 1) return true;
        }
        return false;
    }
};
