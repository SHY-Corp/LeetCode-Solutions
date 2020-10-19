// Runtime: 16 ms
// Simple implementation solution

int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(target<=nums[0])  // It checked if the the number to be inserted is smaller than the first element of the vector and if it is, the number is to be inserted before it. Thus, position which will be 0, to be returned.
            return 0;
        if(target>nums[n-1])  // It checked if the the number to be inserted is larger than the last element of the vector and if it is, the number is to be inserted after it. Thus, position which will be n, to be returned.
            return n;
        for(int i=0;i<n-1;i++)
        {
            if(target>=nums[i] && target<=nums[i+1])  // It checked if the the number lies between any two elements of the vector and if it is, the number is to be placed between them. Thus, position which will be i+1, to be returned.
                return i+1;
        }
        return 0;
    }
