//Given a non-negative integer num, return the number of steps to reduce it to zero. 
//If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

class Solution {
public:
    int numberOfSteps (int num) {
        int counter = 0;
        while(num)
        {
            if(num%2==0)
            {
                num = num/2;
            }
            else
            {
                num = num-1;
            }
            counter++;
        }
        return counter;
    }
};
