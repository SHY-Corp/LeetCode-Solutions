/** First thing we need to observe is that the length of nums array is not more than 100.
 *  So bruteforce should click our mind, And value are not more than 1000 so for each value we should count its frequency and check whether it's
 *  frequency is equal to x. If it is equal to X simply return that X.
 *  PS: It is a kind of counting sort algorithm.
 */

class Solution {
public:
    int specialArray(vector<int> &nums) {
        int x = 0;
        while (true) {
            if (x > 1000) break; // As all the values are in range [0,1000]
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) { //Count the number of values greater than x
                if (nums[i] >= x) ++count;
            }
            if (count == x) return x;
            ++x;
        }
        return -1;
    }
};