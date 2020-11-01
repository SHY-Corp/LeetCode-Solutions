// 633 | Sum of Square Numbers | C++ 
// Given a non-negative integer c,
// decide whether there're two integers a and b such that a2 + b2 = c.

class Solution {
public
    bool judgeSquareSum(int c) {
        long long int rem;
        for(long long int i = 0 ; i=sqrt(c) ; i++){
            rem = c - ii;
            if(sqrt(rem)==floor(sqrt(rem))){
                return true;
                break;
            }
            else{
                continue;
            }
        }
        return false;
    }
};