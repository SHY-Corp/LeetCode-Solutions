//Link https://leetcode.com/problems/valid-number/
class Solution {
public:
    bool isNumber(string str) {
        int o=0,e=0,count=0,d=0;
        int n=str.length();
        char c;
        for(int i=0;i<n;i++)
        {   
            c=str[i];
            if(int(c)>47&&int(c)<58)//Detect number using ASCII values
            {

               count++; 
            }
            else if(c=='e'&&count>0&&(isdigit(str[i+1])==1||str[i+1]=='+'||str[i+1]=='-')&&e==0)
            {
                e++;
            }
            else if(str[i]=='.'&&d==0) 
            {
                d++;
             if(isdigit(str[i+1])==1||isdigit(str[i-1])==1){ }
                else
                 return false;
                if(e!=0)
                    return false;
            }
            else if((c=='+'||c=='-')&&i!=n-1)
            {
                if(i==0)
                {o++;}
                else if((str[i-1]=='e')||((o==0)&&(count==0))||(str[i-1]=='e'))
                o++;
                else 
                    return false;
            }
            else if(str[i]==' '){
            int left =n-(i+1);
                if(left>0)
                {
                if(((isdigit(str[i+1])==1||str[i+1]=='e')&&count>=1)||(o==1&&count==0))
            {

                    return false;
            }
                }
               else if(count>0 &&i+1!=n) return false;
                else if(i+1==n && count==0 ) return false;
            }
                else
                    return false;
                }

        return true;
    }
};
