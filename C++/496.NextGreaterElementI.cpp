class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> result(n);

        //map for storing greater next from values in nums[2]
        unordered_map<int, int> gnext;

        //for processing values from nums[2]
        stack<int> s;

        int temp;

        for(int i=m-1; i>=0; i--)
        {
            //while the stack is not empty and the top value is less than nums2[i], keep popping the stack
            while(!s.empty() && s.top()<nums2[i])
            {
                s.pop();
            }

            //if the stack is not empty, store the top element of stack in a temporary variable
            if(!s.empty())
                temp = s.top();
            else
                temp = -1;

            //push the current nums2[i] in stack and store the temp variable(above) in gnext[nums2[i]];
            s.push(nums2[i]);
            gnext[nums2[i]] = temp;
        }

        for(int i=0; i<n; i++)
        {
            //we already have gnext[nums1[i]] computed above
            result[i] = gnext[nums1[i]];
        }

        return result;
    }
};
