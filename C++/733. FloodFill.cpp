/*Description of FloodFill algorithm - We are given an image(2d vector) and starting pixel we have to change the colour of the starting pixel,
plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected
4-directionally to those pixels (also with the same color as the starting pixel), and so on to the new colour which is given in the input.*/ 

class Solution {
public:
    
    bool vis[55][55]; // Visited array
    
    int dx[4]={-1,0,0,1};
    int dy[4]={0,1,-1,0}; // All the four directions to perform the dfs in the image
    
    void dfs(int x,int y,int newColor,vector<vector<int>>& image,int c){
        vis[x][y]=1;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int e=x+dx[i];
            int f=y+dy[i];
            if(e>=0 && e<n && f>=0 && f<m){
                if(vis[e][f]==0 && image[e][f]==c){
                    dfs(e,f,newColor,image,c);
                }
            }
        }
        image[x][y]=newColor;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        memset(vis,0,sizeof vis);
        dfs(sr,sc,newColor,image,image[sr][sc]);
        return image;
    }
};
