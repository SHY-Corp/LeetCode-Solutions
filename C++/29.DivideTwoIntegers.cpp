class Solution {
public:
    int divide(int dividend, int divisor) {
        //time limit exceeding with this approach
        //TC: O(dividend/divisor) and SC:O(1)
        /*
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        if(dividend==INT_MAX && divisor==-1)
            return INT_MIN;

        int sign = (dividend<0) ^ (divisor<0) ? -1 : 1;

        long int dend = abs(dividend);
        long int isor = abs(divisor);

        long quotient=0;
        while(dend>=isor)
        {
            dend = dend - isor;
            quotient++;
        }
        return quotient*sign;
        */

        //edge case
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;

        //storing the sign that will be used for final result
        int sign = (dividend<0) ^ (divisor<0) ? -1 : 1;

        //getting rid of -ve values for now
        long dend = abs(dividend);
        long isor = abs(divisor);

        long quotient=0;

        //iterating till our dividend is >= divisor
        while(dend-isor >= 0)
        {
            //this variable is essentially an exponent and we will use the shift left operator to multiply by 2
            long temp=0;
            //increment the exponent as long as the difference of dividend & divisor(after <<) is +ve
            while(dend-(isor<<1<<temp) >= 0)
                temp++;

            //increment the quotient, once again by using shift left
            quotient += 1<<temp;
            //decrement the dividend by left shifting the divisor by temp
            dend -= isor<<temp;
        }

        //multiplying the quotient with its respective sign
        return sign*quotient;
    }
};
//TC: O(log(dividend)), SC: O(1)
