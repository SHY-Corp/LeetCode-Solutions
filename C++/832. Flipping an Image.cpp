// problem - 832. Flipping an Image

/*
    Given a binary matrix A, we want to flip the image horizontally, then invert it, 
    and return the resulting image.

    To flip an image horizontally means that each row of the image is reversed. 
    For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

    To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. 
    For example, inverting [0, 1, 1] results in [1, 0, 0].
*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& nums) {
        vector<vector<int>> answer;
        for(vector<int> num: nums) {
            vector<int> temp;
            int n = num.size();
            // pushing all row elements in reverse order
            for(int i=n-1; i>=0; i--) {
                if(num[i] == 1) temp.push_back(0);
                else temp.push_back(1);
            }
            
            answer.push_back(temp);
        }
        
        return answer;
    }
};

// Time Complexity = O(N*M) 
// Space Complexity = O(N*M) [where N is number of rows and M is number of columns]