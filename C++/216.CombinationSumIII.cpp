/* Very similar to combination sum ii. I would suggest you try 39. Combination Sum
   and 40. Combination Sum II first. 

   Difference between Combination Sum II and III is that III requires us to find
   combinations where 'k' numbers add up to 'n' target and those k numbers
   lie between 1 and 9. So, we have a candidates array which I have named as 'v'
   and it is initialized to {1,2,3,4,5,6,7,8,9}. We can also use a 'for-loop' to 
   input these values. I initialized this array for my understanding.

   From here, the approach is similar to that of Combination Sum II. 
   (Backtracking and recursion)

   Note the base condition though!
*/

class Solution {
public:
    vector<int> result;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> temparray;
        sumToN(v,temparray,n,k);
        return temparray;
    }
    
    void sumToN(vector<int>& v, vector<vector<int>>& temparray, int target, int k, int j=0)
    {
        int i;
        
        if(target<0)
            return;
        
        else{
               /*Base condition
                 I am recursively subtracting each value in 'v' from n(i.e. target), so
                 if it becomes 0 AND the size of final vector(result), in which I am pushing my temporary
                 vector(temparray), is equal to 'k', then I get one of my combinations!

                 The latter condition is IMPORTANT. If I don't include it, I am just getting all possible
                 combinations of numbers in 'v' adding upto my target.
               */
               if(target==0 && result.size()==k)      
                  return temparray.push_back(result); 
               else{
                  for(i=j; i<v.size(); i++)
                   {
                       if(target-v[i]>=0)
                         {
                           result.push_back(v[i]);
                           sumToN(v, temparray, target-v[i], k, i+1);
                           result.pop_back();    //We don't want to consider that number which didn't contribute towards our target.
                         }
                   }
                   }
            }
    }
};