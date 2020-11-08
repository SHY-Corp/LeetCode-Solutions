class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n, i;
        n = nums.size()-1;
        
        /* Commenting out this solution because 
           its time limit exceeded!!
        for(i=1; i<=n; i++)
        {
            for(j=0; j<i; j++)
                  if(nums[i]==nums[j])
                    return true;  
            
        }
        return false; */
        
        /* I sort the array first, then I traverse it and 
           check if the adjacent values are equal or not.
           So if, they are equal, the function returns
           true, else, it returns false; 
        */
        sort(begin(nums), end(nums));
        for(i=1; i<=n; i++)
        {
            if(nums[i - 1]== nums[i])
                return true;
        }
        return false;
    }
};