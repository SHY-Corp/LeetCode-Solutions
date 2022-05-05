/*class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ops = 0;
        sort(begin(nums), end(nums));
        int start = 0;
        int end = nums.size()-1;

        while(start<end)
        {
            int temp = nums[start]+nums[end];
            if(temp==k)
            {
                ops++;
                start++;
                end--;
            }
            else if(temp<k)
                start++;
            else
                end--;
        }
        return ops;
    }
};

/*
    TC: O(nlongn)
    SC: O(1)
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ops = 0;
        int temp;
        unordered_map<int, int> m;

        for(int i=0; i<nums.size(); i++)
        {
            //fixing 1 value as nums[i] and looking for k-nums[i] in the map
            temp = k-nums[i];

            //if the value exists, incrementing the operations count and decrementing the value from map
            if(m[temp]>0)
            {
                ops++;
                m[temp]--;
            }
            //if not, adding nums[i] value to the map
            else
                m[nums[i]]++;
        }
        return ops;
    }
};

/*
   TC: O(n)
   SC: O(n)
*/
