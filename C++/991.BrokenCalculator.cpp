class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ops = 0;

        while(target > startValue)
        {
            /*we are deliberately making the target value even if it's odd because the number of operations reduce
              if we multiply or divide instead of repeatedly adding values,
              e.g., 1+1+1+1+1=5(4 operations), 1*5=5(1 operation)!
             */
            if(target%2==1)
                target++;
            //divide the target by 2 if it's even
            else
                target=target/2;

            ops++;
        }

        //startValue - target is the number of additions(+1s) we will need to reach the startValue
        ops = ops + (startValue - target);
        return ops;
    }
};
