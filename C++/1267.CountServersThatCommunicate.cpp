//problem statement : https://leetcode.com/problems/count-servers-that-communicate/

//solution :

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rows(grid.size(), 0), cols(grid[0].size(), 0);
        
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]){
                    rows[i]++, cols[j]++;
                }
            }
        }
        int res = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] && (cols[j] > 1 || rows[i] > 1)){     // check if there are any other server except the current one in it's corresponding row or column.
                    res += 1;
                }
            }
        }
        return res;
    }
};
