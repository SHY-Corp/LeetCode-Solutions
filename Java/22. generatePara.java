import java.util.*;
class Solution {
    void solve(int open, int close , String op,ArrayList res)
    {
        if(open==0 && close==0)
        {
            res.add(op);
            return;
        }
        if(open!=0)
        {
            String op1=op+"(";
           // open--;
            solve(open-1,close,op1,res);
        }
        if(close>open)
        {
            String op2=op+")";
           // close--;
            solve(open,close-1,op2,res);
        }
        return ;
    }
    public List<String> generateParenthesis(int n) {
        ArrayList<String> res=new ArrayList<>();
        int open = n;
        int close = n ;
        String op = "";
        solve(open,close,op,res);
        
        return res;
    }
}
