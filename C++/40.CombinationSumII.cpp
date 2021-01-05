/* I have solved this problem using recursion and backtracking. The approach is somewhat
   similar to that of 39.Combination Sum. The only difference is, we need to make sure that
   we don't repeat the elements while backtracking.
*/
class Solution {
public:
    /* No specific reason for declaring this array globally except that I won't be using it 
       frequently unlike other vectors and variables, so when I pass parameters, the function
       will be much cleaner and understandable;
    */
    vector<int> result; 
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<vector<int>> temparray;
        targetArray(temparray, candidates, target);
        return temparray;
    }
    
    void targetArray(vector<vector<int>>& temparray, vector<int>& candidates, int target, int j=0)
    {  
        int i,n;
        n = candidates.size();
        
        /* This is my base condition. If my traget value is 0, it means that I have one of the combinations
           which I then push into temparray;
        */
        if(target==0 || n==0){
            return temparray.push_back(result);
        }
        
        for(i=j; i<n; i++)
        {
            if(i>j && i!=0 && candidates[i]==candidates[i-1])  //condition for checking if there are duplicates
                continue;                                      //so if it's true, we continue
            
            if(target-candidates[i]<0)                         //if my computations yield a negative number, I return
                return;
            
            /* Here, I will keep checking my value for "target-candidates[i] till it's +ve or = to 0, and keep adding
               those elements to the result vector, thereby making a recursive call once again and popping the last 
               element in the result if it was not a potential candidate, i.e., it doesn't sum up to target.
               
               Note, I am passing 'i+1' while recursively calling the helper function so that I can compute values for
               the next index. If I simply pass 'i', it will keep getting 0 as its initial value and the elements would
               eventually repeat.
            */
            if((target-candidates[i])>=0)
            {
                result.push_back(candidates[i]);
                targetArray(temparray, candidates, target-candidates[i], i+1);
                result.pop_back();
            }
            else
                return;
        }
    }       
};