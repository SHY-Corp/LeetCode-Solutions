/*

   Problem Statement :
        #15 .
             Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
             Find all unique triplets in the array which gives the sum of zero.
             Notice that the solution set must not contain duplicate triplets.

    Constraints:
        0 <= nums.length <= 3000
        -10^5 <= nums[i] <= 10^5

    Approach:
             The constraints allow us to use O(n^2) approach. Hence we shall traverse the array and for each given element we
             shall convert the problem to Two Sum problem. To use two sum approach we define a target which is the difference
             of 0 and say the number c ( since a+b+c = 0 , a+b = 0 - c ) . Now the question is left as a two sum problem
             where we find a and b. We sort and check for all the duplicates , the final vector only has unique elements
             that make up the sum.

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Results vector
        vector<vector<int>> res;
        // We sort to apply the two sums approach
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i< nums.size(); i++){
            int target = -nums[i];
            int front = i+1;
            int back = nums.size()-1;

            while(front< back){
                int sum = nums[front] + nums[back];

                if(sum < target)
                    front++;
                else if(sum > target )
                    back--;
                else{
                    vector<int> temp(3,0);
                    temp[0] = nums[i];
                    temp[1] = nums[front];
                    temp[2] = nums[back];
                    res.push_back(temp);

                    //Checks for duplicates for the sorted array at the front end
                    while(front < back && nums[front] == temp[1])
                        front++;

                    //Checks for duplicates for the sorted array at the back end
                    while(front < back && nums[back] == temp[2])
                        back--;
                }
            }

            //Checks for duplicate number
            while(i+1< nums.size() && nums[i+1] == nums[i])
                i++;
        }
        return res;
    }
};
