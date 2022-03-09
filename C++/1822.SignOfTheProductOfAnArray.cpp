class Solution {
public:
    int arraySign(vector<int>& nums) {
    /*    if(count(nums.begin(), nums.end(), 0))
            return 0; */

    /*    int prod = 1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
               return 0;

            if(nums[i] > 0)
            {
                nums[i] = 1;
                prod = prod * nums[i];
            }
            if(nums[i] < 0)
            {
                nums[i] = -1;
                prod = prod * nums[i];
            }
        }
        return prod;  */

        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                return 0;
            //incrementing the count if we encounter a -ve number
            if(nums[i]<0)
                count++;
        }

        //product of 2 -ve numbers is always +ve and product of a -ve and a +ve number is -ve.
        //so if there are odd no. of -ve values in the array, the final product will be -ve, otherwise +ve.
        if(count%2==1)
            return -1;
        else
            return 1;
    }
};
