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