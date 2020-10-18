class Solution:
    def bfs(self,q):
        
        ans = 0
        while len(q)!=0:
            i1, j1, k = q.pop(0)
            
            ans = max(ans, k)
            
            #top
            if i1>0 and self.grid[i1-1][j1] == 1:
                
                self.grid[i1-1][j1] += 1
                q.append([i1-1,j1,k+1])
            
            #down
            if i1<len(self.grid)-1 and self.grid[i1+1][j1] == 1:
                
                self.grid[i1+1][j1] += 1
                q.append([i1+1,j1,k+1])
                
            #right
            if j1<len(self.grid[0])-1 and self.grid[i1][j1+1] == 1:
          
                self.grid[i1][j1+1] += 1
                q.append([i1,j1+1,k+1])
                
            #left
            if j1>0 and self.grid[i1][j1-1] == 1:
       
                self.grid[i1][j1-1] += 1
                q.append([i1,j1-1,k+1])
                
            
                
        return ans
                
            
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        q = []
        self.grid = grid
        
       
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==2:
                    q.append([i,j,0])
                    
        ans = self.bfs(q)        
        label = False            
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    label = True
                    break
            if label:
                break
        if not label:
            return ans
        else:
            return -1
                
        