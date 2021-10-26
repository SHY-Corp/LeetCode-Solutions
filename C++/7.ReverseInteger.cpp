class Solution {
public:
    int reverse(int x) {
        long a,rev;
        rev=0;
        while(x!=0)
        {
            a=x%10;        //storing the remainder(or the last digit of a number) in integer a
            x=x/10;        //reducing the original number to its quotient in each step

            if(rev>INT_MAX/10 || (rev==INT_MAX/10 && a>7))  //overflow condition
                return 0;
            if(rev<INT_MIN/10 || (rev==INT_MIN/10 && a<-8)) //underflow condition
                return 0;

            //multiplying the integer rev with 10 and adding the value of 'a' at each step so it increases
            //successively and the value gets stored in reverse.
            rev= rev*10 + a;
        }
        return rev;
    }
};
