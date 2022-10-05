/**
 *created by vipul-2003
 * @brief this is leetcode Question 1854. Maximum Population Year 
 * link :: https://leetcode.com/problems/maximum-population-year/
 */

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) 
    {
        int size = 101;
        int arr[size] ;
        for ( int i = 0 ; i < size ; i++) // initialize the array with zero 
            arr[i] = 0 ;
        
        for ( int i = 0 ; i < logs.size() ; i++)
        {
            int j = 0 ;
            ++arr[logs[i][j] - 1950]; // increment the value by one for birth 
            
            int k = 1 ;
            --arr[logs[i][k] -1950]; // decrement the value by one for death 

        }
        
        int sum = 0;
        int max = INT_MIN; // to initialize the value with possible lowest minimum integer 
        int address ;
        
        for (int i = 0 ; i < size ; i++)
        {
            sum += arr[i];
            arr[i] = sum ;
            
            if ( max < arr[i]) 
            {
                max = arr[i] ;
                address = i+1950 ; // for storing the address of the first maximum number 
            } 
        }
        
        return address ;
    }
};
