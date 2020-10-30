//BFS solution. 
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size(), n = board[0].size();
        for(int i =0; i < m; i++){
            if(board[i][0] != 'X') bfs(i, 0, board);
            if(board[i][n-1] != 'X') bfs(i, n-1, board);
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] != 'X') bfs(0, j, board);
            if(board[m-1][j] != 'X') bfs(m-1, j, board);
        }
        
        for(int i =0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
        
    }
    
    void bfs(int i, int j, vector<vector<char>>& board){
        queue<pair<int, int>> q;
        q.push(pair<int, int>(i,j));
        while(!q.empty()){
            int ii = q.front().first, jj = q.front().second;
            q.pop();
            if(ii<0 || jj<0 || ii>=board.size() || jj>=board[0].size()) continue;
            if(board[ii][jj] == 'X' || board[ii][jj] == '#') continue;
            board[ii][jj] = '#';
            q.push(pair<int, int>(ii+1, jj));
            q.push(pair<int, int>(ii-1, jj));
            q.push(pair<int, int>(ii, jj+1));
            q.push(pair<int, int>(ii, jj-1));
        }
    }
};
