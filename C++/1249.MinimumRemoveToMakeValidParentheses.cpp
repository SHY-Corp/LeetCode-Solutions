class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.empty())
            return s;

        int balance = 0;
        string final="";

        //traversing the string from the start
        for(int i=0; i<s.size(); i++)
        {
            //increment the balance variable if there is an open bracket
            if(s[i]=='(')
                balance++;

            //if there is a closing bracket, check the balance variable first
            //if balance is 0, it implies that there was NO OPEN bracket previously, thus this is extra and
            //for now we are marking it with another symbol, in this case '*', else we decrease the count
            //implying that we found a pair which is balanced
            else if(s[i]==')')
            {
                if(balance==0)
                    s[i] = '*';
                else
                    balance--;
            }
        }

        //resetting the balance variable again
        balance = 0;

        //iterating the string from the end
        for(int i=s.size()-1; i>=0; i--)
        {
            //doing the same steps we did in the previous loop, except, this time, we check the closing bracket
            //before the opening bracket, and mark the extra bracket as '*', as we are traversing from the end
            //and need to make sure that we don't leave excess ')' unchecked
            if(s[i]==')')
                balance++;

            else if(s[i]=='(')
            {
                if(balance==0)
                    s[i]='*';
                else
                    balance--;
            }
        }

        //updating the final string without the marked characters
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!='*')
                final.push_back(s[i]);
        }
        return final;
    }
};
