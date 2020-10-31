class Solution {
public:
    int mySqrt(int x) {
        long long left=0,right=x;
        if(x==0)
            return 0;
        if(x==1)
            return 1;
        while(left<right){
            long long middle=left+(right-left)/2;
            if(middle*middle==x)
                return middle;
            else if(middle*middle>x)
                right=middle-1;
            else
                left=middle+1;
        }
        if(left*left>x)
            return left-1;
        else
            return left;
    }
};