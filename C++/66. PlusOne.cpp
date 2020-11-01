/*
 * Given a non-empty array of digits representing a non-negative integer, increment one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 *
 *
 *
 * Example 1:
 *
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 *
 * Example 2:
 *
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 *
 * Example 3:
 *
 * Input: digits = [0]
 * Output: [1]
 */
 // ----------------------------------Solution--------------------------------
 /*
  * Starting from end, if the last digit is other than zero, we are adding one and returning the digits.
  * If the last or second last digit is 9, then we are making those digits as 0 and incrementing the digit previous to them digit and returning it.
  * If all the digits are 9, then all the digits will become 0. Then, we are appending 1 in the most sigificant place.
  *
  */
  
  class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int size = digits.size();
        
        for(int i=size-1; i>=0; i--) {
            if( digits[i] != 9 ) {
                digits[i]++;
                break;
            }
            else {
                digits[i]=0;
            }
        }
        
        if(digits[0] == 0) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
