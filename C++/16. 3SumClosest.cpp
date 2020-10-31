//Problem 16
// Find the closest sum of 3 numbers out of all the elements of an array given a target input





class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int closestSum = nums[0] + nums [1] + nums[n-1];   //Initially closestSum = initial triplet sum
        sort(nums.begin(),nums.end());
        while(i < n -2){
            int j = i+1;
            int k = n-1;         
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k] ;
                if(sum == target)               //if triplet sum becomes equal to target, then that is the closestSum itself
                    return sum;
                if (abs(target - sum) < abs(target - closestSum)){
                    closestSum = sum;       //if sum of current triplet is closer than target than the previous closestSum,
				}                                        //we update the closestSum value to the current triplet sum
                if(sum > target)
                    k--;
                else if(sum <target)
                    j++;
            }
            i++;
        }
        return closestSum;
    }
};
