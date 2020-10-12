// Check whether the given sudoku board is valid or not

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    // main function to iterate over the board
    
        int size=board.size();
        
        // iterate over the board
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(board[i][j]!='.'){
                
                    // skip the '.' character since there is no number there.
                    char ch=board[i][j];
                    if(!isSafe(board,i,j,ch,size)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isSafe(vector<vector<char>>&board,int row,int col,char ch,int size){
        // checking row
        for(int k=0;k<size;k++){
            if(k!=row && board[k][col]==ch){
                return false;
            }
        }
        // checking col
        for(int k=0;k<size;k++){
            if(k!=col && board[row][k]==ch){
                return false;
            }
        }
        // checking grid
        int s=sqrt(size);
        int rs=row-row%s;
        int cs=col-col%s;
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
               if(row==(i+rs) || col==(j+rs) ){
                   continue;
               }
                if(board[i+rs][j+cs]==ch){
                    return false;
                }
            }
        }
        return true;
    }
    
};
