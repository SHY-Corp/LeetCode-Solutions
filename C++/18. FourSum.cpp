/*
   4Sum problem can be understood as an array of length N and a target X. We need to find all the quadruplets, i.e., 4 elements
   whose sum is equal to X.
   
   SOLUTION:
   How fourSum() works?
    1. Take two variables, one which is vector of vectors A and other a vector tempA.
    
    2. Check if size of array A is atleast 4 as we need to form quadruplets.
    
    3. Sort the aray A.
    
    4. We need to loop as following, if size=(length of array):
        Outer loop from i=0 to i<size-3:
            A. Nested loop from j=i+1 to j<size-2:
                    A.a. Take two variables, left=j+1 and right=size-1
                    A.b. Take the difference of X-(A[i]+A[j]) as tempTarget, where X is target.
                    A.c. Loop while left<right and do the following: // This step can be understood as a twoSum function.
                            i. consider the sum of A[left] and A[right].
                            
                            ii. if(sum==tempTarget) do the following:
                                i.i. push back A[i] to vector tempA.
                                i.ii. push back A[j] to vector tempA.
                                i.iii. push back A[left] to vector tempA.
                                i.iv. push back A[right] to vector tempA.
                                i.v. Loop and increase left until left<right and A[left]==tempA[2] in-order to remove duplicates.
                                i.vi. Loop and increase left until left<right and A[right]==tempA[3] in-order to remove duplicates.
                                i.vii. finally clear the tempA vector for next set of operations to avoid conflicts.
                                
                            iii. else if(sum>tempTarget):
                                    this means we need to decrease the sum so we perfrom right--;
                            iv. else increase left by 1, i.e., left++ in-order to increase the sum value.
                            
                    A.d. Loop until j+1<size-2 && A[j+1]==A[j], increase j by 1, i.e., j++, in-order to remove duplicates.
            
            B. Loop until i+1<size-2 && A[i+1]==A[i], increase i by 1, i.e., i++, in-order to remove duplicates.
            
    5. return A
         
*/

class Solution {
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> A;
        vector<int> tempA;
        int size=nums.size();
        
        if(size>=4){
            for(int i=0; i<size-3; i++){
                for(int j=i+1; j<size-2; j++){
                    int tempTarget=target-(nums[i]+nums[j]);
                    int left=j+1, right=size-1;
                    while(left<right){
                        int sum=nums[left]+nums[right];
                        if(sum==tempTarget){
                            tempA.push_back(nums[i]);
                            tempA.push_back(nums[j]);
                            tempA.push_back(nums[left]);
                            tempA.push_back(nums[right]);
                            A.push_back(tempA);
                            while((left<right) && (nums[left]==tempA[2])) left++;
                            while((left<right) && (nums[right]==tempA[3])) right--;
                            tempA.clear();
                        }
                        else if(sum>tempTarget) right--;
                        else left++;
                    }
                    while((j+1<size-2) && (nums[j+1]==nums[j])) j++;
                }
                while((i+1<size-3) && (nums[i+1]==nums[i])) i++;
            }
        }
        return A;
    }
};