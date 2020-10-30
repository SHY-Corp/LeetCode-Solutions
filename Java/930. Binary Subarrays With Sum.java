//In an array A of 0s and 1s, how many non-empty subarrays have sum S?

// Input: A = [1,0,1,0,1], S = 2
// Output: 4
// Explanation: 
// The 4 subarrays are bolded below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]

//Approach 
// Using sliding window technique


class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
	    // calculate all subarrays less and equal to sum S minus all subarrays less and equal to sum S - 1
        return numSubarraysLessAndEqualToSum(A, S) - numSubarraysLessAndEqualToSum(A, S - 1);
    }
    
    private int numSubarraysLessAndEqualToSum(int[] A, int S) {
        int lo = 0;
        int hi = 0;
        int sum = 0;
        int num = 0; // to calculate all legit subarrays end with hi
        while (hi < A.length) {
            sum += A[hi];            
            while (lo <= hi && sum > S) {
			    /* currently subarray end with hi is not valid, we need to forward lo*/
                sum -= A[lo++];
            }
            num += hi - lo + 1;
            hi++;
        }
        return num;
    }
}




