/*
Submitted by vipul kumar singh
question link :: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int count = 0;
        
        for(int i = 0 ; i <nums.size() ;i++)
        {
            int number= 0 ; 
            
          while(nums[i] > 0)
          {
              ++number;  //preincrement of number 
              nums[i] =  nums[i]/10;  // divide ith index element of nums by 10
          }
          
            // ternuary operator for incrementing value of count if number is divisible by 2
            number%2 == 0 ? ++count : count ; 
        }
       
       // there is one other way short way of doing this in commented form 
        /*
        int count = 0;
        
        for(int i = 0 ; i <nums.size() ;i++)
        {
            int number= 0 ; 
            
            number = log10(nums[i]) + 1 ;
            number%2 == 0 ? ++count : count ;
        }
        
        */
        
        return count ;
        
    }
};
