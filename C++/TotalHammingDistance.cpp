class Solution {
 public :
     int totalHammingDistance(vector< int >& nums) {
         int res = 0 , n = nums.size();
         for ( int i = 0 ; i < 32 ; ++ i) {
             int cnt = 0 ;
             for ( int num: nums) { // counts set bits at pos i from right
                 if (num & ( 1 << i)) ++ cnt;
            }
            res += cnt * (n- cnt); // #setBit * #UnsetBit
        }
        return res;
    }
};

//4: 0 1 0 0

//14: 1 1 1 0

//2: 0 0 1 0

//1: 0 0 0 1

//By observing the above binary form, Imp rule identified here is 
//Number of Setbit * number of unsetbit 
