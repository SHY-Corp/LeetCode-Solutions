/* Program name :- Reverse_Integer.cpp
 this program will receive any 3 digit number whether it is positive or negative and convert it into its reversed form or reverse its digits ,
 and this program also works if the situation overflows.
*/


public class Solution {

     public static int reverse(int x) {
            int ret = 0;
            boolean zero = false;
            while (!zero) {
                ret = ret * 10 + (x % 10);
                x /= 10;      
                if(x == 0){
                    zero = true;
                }
            }
            return ret;   
        }

    public static void main(String[] args) {
        int s = 1000000003;
        System.out.println(reverse(s));
    }

}
