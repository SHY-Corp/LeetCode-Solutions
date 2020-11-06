/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2*/
class Solution {
public:
    
    int findCandidate( vector<int>a, int size) 
{ 
    int maj_index = 0, count = 1; 
    for (int i = 1; i < size; i++) { 
        if (a[maj_index] == a[i]) 
            count++; 
        else
            count--; 
        if (count == 0) { 
            maj_index = i; 
            count = 1; 
        } 
    } 
    return a[maj_index]; 
} 
  
/* Function to check if the candidate 
   occurs more than n/2 times */
bool isMajority(vector<int>a, int size, int cand) 
{ 
    int count = 0; 
    for (int i = 0; i < size; i++) 
  
        if (a[i] == cand) 
            count++; 
  
    if (count > size / 2) 
        return 1; 
  
    else
        return 0; 
} 
  
/* Function to print Majority Element */
int majorityElement(vector<int>a) 
{ 
    int size = a.size();
    /* Find the candidate for Majority*/
    int cand = findCandidate(a, size); 
  
    /* Print the candidate if it is Majority*/
    if (isMajority(a, size, cand)) 
       return cand;
  
    else
        return -1; 
}

      
};
