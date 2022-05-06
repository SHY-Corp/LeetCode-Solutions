class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> temp;
        string ans = "";

        //iterating over each character in the string and storing it with its count in a stack
        for(auto x: s)
        {
            //push the character with its current count if the stack is empty
            if(temp.empty())
                temp.push({x, 1});

            //if the charcter is repeating, increment its count
            else if(temp.top().first == x)
                temp.push({x, temp.top().second+1});

            //if the charcter isn't repeating and the stack is also not empty, push the new character
            else
                temp.push({x, 1});

            //if the character count is greater than or equal to k, pop the k duplicate elements
            if(temp.top().second >= k)
            {
                for(int i=1; i<=k; i++)
                    temp.pop();
            }
        }

        //iterating over the remaining elements in the stack and adding them to the result string
        while(!temp.empty())
        {
            ans += temp.top().first;
            temp.pop();
        }
        //reversing the string from previous step as adding the top element from the stack to the result
        //string will be in reverse order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
    TC: O(n)
    SC: O(n)
*/
