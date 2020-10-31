class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;
        
        //left border
        for (int row = 0;  row < board.size(); ++row)
            if (board[row][0] == 'O')
                floodFill(board, row, 0, 'O', 'T');
        //top border
        for (int col = 1; col < board[0].size(); ++col)
            if (board[0][col] == 'O')
                floodFill(board, 0, col, 'O', 'T');      
        //right border
        for (int row = 1; row < board.size(); ++row)
            if (board[row][board[0].size() - 1] == 'O')
                floodFill(board, row, board[0].size() - 1, 'O', 'T'); 
        //bottom border
        for (int col = 1; col < board[0].size() - 1; ++col)
            if (board[board.size() - 1][col] == 'O')  
                floodFill(board, board.size() - 1, col, 'O', 'T');   
        
        for (int row = 0; row < board.size(); ++row)
            for (int col = 0; col < board[0].size(); ++col)
            {
                if (board[row][col] == 'T')
                    board[row][col] = 'O';
                else
                    board[row][col] = 'X';
            }
    }
private:
    void floodFill(vector<vector<char>>& board, int row, int col, char origCh, char newCh) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return;
        if (board[row][col] != origCh)
            return;
        board[row][col] = newCh;
        floodFill(board, row, col - 1, origCh, newCh);
        floodFill(board, row - 1, col, origCh, newCh);
        floodFill(board, row, col + 1, origCh, newCh);
        floodFill(board, row + 1, col, origCh, newCh);
    }; 
};
