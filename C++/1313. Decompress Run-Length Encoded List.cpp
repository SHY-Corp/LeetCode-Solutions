
/** This is cake-walk problem, with simple bruteforce approach.
 *  Here we were given a value and its frequency and we have to make a new vector so that each value is repeated
 *  equivalent to its frequency times.
 *  So in the input even indices represents frquency and odd indices represents particular value. (Zero based indexing)
 *  So simply walk through the even indices and get the adjacent value and put that value in the new vector for desired number of times.
 */

class Solution {
public:
    vector<int> decompressRLElist(vector<int> &nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i += 2) { //loop through even indices
            int frequency = nums[i];  //Get the frequency
            int value = nums[i + 1];    //Get the particular value
            for (int j = 0; j < frequency; ++j) { // Add that value to new vector for frquency times
                ans.push_back(value);
            }
        }
        return ans;
    }
};