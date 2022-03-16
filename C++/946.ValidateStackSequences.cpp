class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> temp;
        int index = 0;

        //iterating over pushed array and pushing their values into the stack
        for(int i=0; i<pushed.size(); i++)
        {
            temp.push(pushed[i]);

            //if the stack is not empty and the current top element is equal to the current index at an element
            //in the popped array, pop the stack and incremnet the index of popped array
            while(!temp.empty() && temp.top()==popped[index])
            {
                temp.pop();
                index++;
            }
        }
        //if the stack is empty, it implies that the sequence of operations: push and pop were possible
        return temp.empty();
    }
};


/**************************************************************************************************************

By treating pushed vector as a stack itself, we are optimizing on space from O(n) to O(1), while the TC remains
the same, i.e. O(n).


   bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      int i=0, index=0;

        for(int a: pushed)
        {
            pushed[i] = a;
            i++;

            while(i>0 && pushed[i-1]==popped[index])
            {
                i--;
                index++;
            }
        }
        return i==0;
     }
*/
