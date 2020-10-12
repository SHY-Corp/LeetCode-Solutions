/*
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 */

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {

        // initialising a has_set to store the values that we have already seen
        unordered_set<int> hash_set;

        // the final resul that we have to return
        int largest_sequence = 0;

        // going through vector and storing the values in the hash set
        for (int i = 0; i < nums.size(); i++)
            hash_set.insert(nums[i]);

        // going through the vector again and computing the sequence
        for (int i = 0; i < nums.size(); i++) {
            int current_num = nums[i];
            int short_sequence = 1;

            // finding if the current_num +1 and curent_num -1 are present in the hash set or not
            if (hash_set.find(current_num - 1) == hash_set.end()) {
                while (hash_set.find(current_num + 1) != hash_set.end()) {
                    current_num++;
                    short_sequence++;
                }
            }

            //finding the maximum between the local sequence and the global sequence
            largest_sequence = max(largest_sequence, short_sequence);

        }


        //returning the largest_sequences
        return largest_sequence;

    }
};