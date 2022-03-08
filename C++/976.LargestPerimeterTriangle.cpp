class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        //sorting the array
         sort(begin(nums), end(nums));

        //iterating from end to check if the lengths satisfy the triangle condition
         for(int i=nums.size()-3; i>=0; i--)
         {
            if(nums[i] + nums[i+1] > nums[i+2])
                return (nums[i]+nums[i+1]+nums[i+2]);
         }
        return 0;
    }
};

/*
    Explanation through an example:
    [3,2,3,4] = [2,3,3,4]  //sorted
              i= 0,1,2,3 , range = 0 to 3
    //iterate from last 3 val to 0 since array is sorted, chances are that the sum of last 3 lengths
    //(forming a valid triangle) will give the largest perimeter

    i=1, nums[1] + nums [2] = 3+3=6 > nums[3]=4, the condition is true, so perimeter =3+3+4=10

    TC=O(nlogn), SC=O(1)
*/
