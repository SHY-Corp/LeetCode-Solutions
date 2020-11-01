// A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

// The world is modeled as a 2-D array of cells, where 0 represents uninfected cells, and 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

// Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region -- the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night. There will never be a tie.

// Can you save the day? If so, what is the number of walls required? If not, and the world becomes fully infected, return the number of walls used.


//Example 1

// Input: grid = 
// [[0,1,0,0,0,0,0,1],
//  [0,1,0,0,0,0,0,1],
//  [0,0,0,0,0,0,0,1],
//  [0,0,0,0,0,0,0,0]]
// Output: 10
// Explanation:
// There are 2 contaminated regions.
// On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

// [[0,1,0,0,0,0,1,1],
//  [0,1,0,0,0,0,1,1],
//  [0,0,0,0,0,0,1,1],
//  [0,0,0,0,0,0,0,1]]

// On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.

//Approach
//Using dfs traversel using graph

class Solution {
    private int[][] dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    private class Count{
        int value = 0;
        public Count(){
            
        }
        public void inc(){
             value++;
        }
    }
    public int containVirus(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        
        int wallCount = 0;
        while(true){
            List<List<int[]>> regionList = new ArrayList();
            List<Count> countList = new ArrayList();
            List<List<int[]>> tList = new ArrayList();
            boolean[][] visited = new boolean[m][n];
            for(int i = 0;i < m;i++){
                for(int j = 0;j < n;j++){
                    if(!visited[i][j] && grid[i][j] == 1){
                        List<int[]> region = new ArrayList();
                        List<int[]> t = new ArrayList();
                        Count count = new Count();
                        visited[i][j] = true;
                        t.add(new int[]{i, j});
                        dfs(region, t, new boolean[m][n], count, grid, m, n, i, j, visited);
                        regionList.add(region);
                        tList.add(t);
                        countList.add(count);
                    }
                }
            }
            int index = -1;
            int maxSize = 0;
            for(int i = 0;i < regionList.size();i++){
                List<int[]> region = regionList.get(i);
                if(region.size() > maxSize){
                    maxSize = region.size();
                    index = i;
                }
            }
            if(index == -1) break;
            
            for(int i = 0;i < regionList.size();i++){
                if(i == index){
                    List<int[]> maxregion = regionList.get(i);
                    wallCount += countList.get(i).value;
                    List<int[]> t = tList.get(i);
                    for(int[] cell : t){
                        grid[cell[0]][cell[1]] = 2;
                    }
                }else{
                    List<int[]> region = regionList.get(i);
                    for(int[] cell : region){
                        grid[cell[0]][cell[1]] = 1;
                    }
                }
            }
        }
        
        return wallCount;
    }
    public void dfs(List<int[]> line,List<int[]> line1, boolean[][] tempvisited, Count count, int[][] grid, int m, int n, int i, int j, boolean[][] visited){
        for(int[] dir : dirs){
            int newi = i + dir[0], newj = j + dir[1];
            if(newi >= 0 && newi < m && newj >= 0 && newj < n){
                if(grid[newi][newj] == 0)   count.inc();
                if(!visited[newi][newj]){
                    if(!tempvisited[newi][newj] && grid[newi][newj] == 0){
                        tempvisited[newi][newj] = true;
                        line.add(new int[]{newi, newj});
                    }else if(grid[newi][newj] == 1){
                        visited[newi][newj] = true;
                        line1.add(new int[]{newi, newj});
                        dfs(line, line1, tempvisited, count, grid, m, n, newi, newj, visited);
                    }
                }
            }
        }
    }
}