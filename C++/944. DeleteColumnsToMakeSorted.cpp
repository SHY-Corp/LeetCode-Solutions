/*
Problem 944 - Delete Columns to Make Sorted

You are given an array of n strings strs, all of the same length.
The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:
abc
bce
cae
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.
Return the number of columns that you will delete.
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = 0;
        if(rows > 0) {
            cols = strs[0].size();
        }
        int colsToDelete = 0;   // answer variable
        // Iter over columns
        for(int j=0; j<cols; j++) {
            int previousChar;
            for(int i=0; i<rows; i++) {
                if(i==0) {
                    previousChar = strs[i][j];
                }else {
                    // Check if previous char and current char are not sorted lexicographically
                    int currentChar = strs[i][j];
                    if(currentChar < previousChar) {
                        colsToDelete++;
                        break;
                    }
                    previousChar = currentChar;
                }
            }
        }
        return colsToDelete;
    }
};