/*
https://leetcode.com/problems/available-captures-for-rook/

On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

*/

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& arr) {
        int n=arr.size();
        int x=-1,y=-1;

        bool flag = 1;
        for(int i=0;flag && i<n;i++){
            for(int j=0;flag && j<n;j++){
                if(arr[i][j]=='R'){
                    x=i;
                    y=j;
                    flag = 0;
                }
            }
        }

        int ret=0;
        for(int j=y;j>=0;j--){
            if(arr[x][j]=='B'){
                break;
            }
            else if(arr[x][j]=='p'){
                ++ret;
                break;
            }
        }

        for(int j=y;j<n;j++){
            if(arr[x][j]=='B'){
                break;
            }
            else if(arr[x][j]=='p'){
                ++ret;
                break;
            }
        }

        for(int i=x;i>=0;i--){
            if(arr[i][y]=='B'){
                break;
            }
            else if(arr[i][y]=='p'){
                ++ret;
                break;
            }
        }
        for(int i=x;i<n;i++){
            if(arr[i][y]=='B'){
                break;
            }
            else if(arr[i][y]=='p'){
                ++ret;
                break;
            }
        }
        return ret;
    }
};