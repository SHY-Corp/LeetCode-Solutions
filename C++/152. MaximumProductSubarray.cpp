// Problem:
// Given an integer array nums, find the contiguous subarray within an array
// (containing at least one number) which has the largest product.

// Approach:
// Since we have to care about both positive and negative product, we will
// store two running products i.e. max_product and min_product
// containing maximum valued and minimum valued products respectively.

// Now, if a negative number is encountered, swap both the products,
// since the sign gets changed. Otherwise, find minimum valued and maximum
// valued subarray products ending at that index as per the standard
// Kadane's algorithm and update the "ans" variable accordingly at each index.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int min_product, max_product, ans;
        min_product = max_product = ans = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
                swap(min_product, max_product);
            min_product = min(nums[i], nums[i] * min_product);
            max_product = max(nums[i], nums[i] * max_product);
            ans = max(ans, max_product);
        }
        return ans;
    }
};
