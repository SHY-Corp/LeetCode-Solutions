class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //traversing through the whole board to find the
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                //backtracking helper function
                if(wordExists(board, word, i, j))
                    return true;
            }
        }
        return false;
    }

    bool wordExists(vector<vector<char>>& board, string word, int x, int y)
    {
        if(word.empty())   //base case: when all the letters in the word are found on the board in sequentially adjacent cells
            return true;
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size())  //boundary case
            return false;

        //if one letter on the board matches with the 1st letter of the word
        if(word[0] == board[x][y])
        {
            board[x][y] = '*';       //mark that coordinate with a special character so recursion won't take the same path

            //search in all 4 directions one letter at a time
            if(wordExists(board, word.substr(1), x, y+1) ||      //UP
               wordExists(board, word.substr(1), x+1, y) ||      //RIGHT
               wordExists(board, word.substr(1), x, y-1) ||      //DOWN
               wordExists(board, word.substr(1), x-1, y))        //LEFT
                return true;
            board[x][y] = word[0];  //give back the value of marked coordinates of board[i][j]
        }
        return false;
    }

};
