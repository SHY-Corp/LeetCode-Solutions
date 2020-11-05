class Solution {
public:
    string convertToBase7(int num) {
        //initialization
        int n=0,x,y;
        string s="";
        y=num;
        //Base case
        if(num==0){s+="0";return s;}
        //Dividing a number unless it is reduced to zero
        while(num!=0){
            x=abs(num%7);
            num=num/7;
            s+=(x+48);
        }
        if(y<0)s=s+"-";
        //reversing the number string
        reverse(s.begin(), s.end()); 
        return s;
    }
};
