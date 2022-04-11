class Solution {
public:
    int calPoints(vector<string>& ops) {

        //stack for storing the record
        stack<int> s;
        int sum = 0;

        for(int i=0; i<ops.size(); i++)
        {
            if((ops[i])=="+")
            {
                //storing the top element(to be pushed later) before popping it
                int x = s.top();
                s.pop();
                //will NOT pop y as we needed 2 integers before "+" to push their sum and don't want to lose
                //access to those values
                int y = x + s.top();
                s.push(x);
                s.push(y);
            }
            else if(ops[i]=="D")
            {
                s.push(s.top()*2);
            }
            else if(ops[i]=="C")
            {
                s.pop();
            }
            else
            {
                s.push(stoi(ops[i]));
            }
        }

        //iterating over the stack and summing its values
        while(!s.empty())
        {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};

//TC: O(n), n = length of ops
//SC: O(n), the space used to store the stack
