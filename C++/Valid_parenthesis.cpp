class Solution {
public:
    bool isValid(string s) {
        vector<char> stack(s.size());
        int top = 0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='[' || s[i]=='{' || s[i]=='(')
                stack[top++]=s[i];
            else if(s[i]==']')
            {
                if(top==0)
                    return false;
                
                char t = stack[top-1];
                top--;
                if(t!='[')
                    return false;
                
            }    
            else if(s[i]==')')
            {
                if(top==0)
                    return false;
                
                char t = stack[top-1];
                top--;
                if(t!='(')
                    return false;
                
            }        
            else if(s[i]=='}')
            {
                if(top==0)
                    return false;
                
                char t = stack[top-1];
                top--;
                if(t!='{')
                    return false;
                
            }    
        }
        if(top!=0)
            return false;
        return true;
    }
};
