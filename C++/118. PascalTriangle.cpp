// Pascal's Triangle 
/*
    Approach - If we have the row of Pascal's triangle, we can easily compute the next row by each pair of adjacent values. 
    Algorithm - Pascal's triangle can be classified as dynamic programming because we construct each row based on the previous row.
    First, we generate the overall triangle list, which will store each row as a sublist. Then, we check for the special case of 000, as we would otherwise return [1][1][1]. 
    If numRows>0numRows > 0numRows>0, then we initialize triangle with [1][1][1] as its first row, and proceed to fill the rows. 
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.reserve( numRows );
        for (int n=0; n<numRows; n++) {
            vector<int> row = {1};              // n choose 0
            row.reserve( n+1 ); 
            for (int k=1; k<=n; k++) {
                row.push_back( row.back() * (n + 1 - k)/k );
            }
            ret.push_back(row);
        }
        return ret;
    }
};