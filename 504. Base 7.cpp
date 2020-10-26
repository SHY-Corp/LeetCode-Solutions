class Solution {
public:
    string convertToBase7(int num) {
        int n=0,x,y;
        string s="";
        y=num;
        if(num==0){s+="0";return s;}
        while(num!=0){
            x=abs(num%7);
            num=num/7;
            s+=(x+48);
        }
        if(y<0)s=s+"-";
        reverse(s.begin(), s.end()); 
        return s;
    }
};
