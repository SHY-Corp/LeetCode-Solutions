//Complexity Analysis

    //Time complexity : O(n)

    //Gauss' formula can be computed in O(1) time, summing nums costs us O(n) time, so the algorithm is overall linear. 
	//Because we have no information about which number is missing.

    //Space complexity : O(1)

    //This approach only pushes a few integers around, so it has constant memory usage.




//Logic is very simple.
//Sum of N arithmetic numbers minus the actual sum of numbers in array will give the missing number
//Example:
//[0,1] : expected sum should be 1,2 = 3, but 0,1 = 1 so missing num is 3-1=2
//[3,0,1] : expected sum should be 1,2,3=6, but 3,0,1=4, so missing number is 6-4=2
//[1,2,3,4] : expected sum should be 1,2,3,4=10, and actual sum = 1,2,3,4=10 so missing number is 10-10=0


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int actual_sum;
        int n= nums.size(); //size of given array
        actual_sum = n*(n+1)/2;  //Actual sum of n numbers
        
        int expected_sum = 0; // Expected sum
        
        for(int i=0;i<nums.size();++i){
            expected_sum+=nums[i]; //Adding total number given in array
        }
        
        return actual_sum-expected_sum; //Return missing value which is Actual sum - Expected sum
        
    }
};
