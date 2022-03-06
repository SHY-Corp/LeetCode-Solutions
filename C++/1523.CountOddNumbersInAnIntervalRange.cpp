class Solution {
public:
    int countOdds(int low, int high) {
        int count;
        int diff = (high-low+1);

        /*if(low%2==0 && high%2==0)
            count = (diff-1)/2;

        if(low%2==1 && high%2==1)
            count = (diff+1)/2;

        if(diff%2==0)
            count = diff/2;*/

        //refactored the above solution:

        if(low%2==0 || diff%2==0)
            count = diff/2;
        else
            count = (diff/2)+1;

        return count;
    }
};

/*
Explanation of the above solution through examples:

1. low = 3,  high = 7   //2 odd numbers
   [3,4,5,6,7]: 7-3+1 = 5 elements; odd: [3,5,7], 3 elements

2. low = 4,  high = 8   //2 even numbers
   [4,5,6,7,8]: 8-4+1 = 5 elements; odd: [5,7], 2 elements

3. low = 4, high = 9    //1st even 2nd odd
   [4,5,6,7,8,9]: 9-4+1 = 6 elements; odd: [5,7,9], 3 elements

4. low = 5, high = 10   //1st odd 2nd even
   [5,6,7,8,9,10] = 6 elements; odd: [5,7,9], 3 elements

   When there are n elements in the range, you will either get (n/2) odd numbers or (n/2)+1 depending on
   the parity of low and high.

   if (low%2==0 && high%2==0) odd = ((high-low+1)-1)/2
   else if (low%2==1 && high%2==1) odd = ((high-low+1) +1)/2
   else if ((high-low+1)%2==0) odd = (high-low+1)/2

   It can be framed better:

   diff = (high-low+1)

   if(low%2==0 || diff%2==0)  count = diff/2; //it will return the quotient irrespective of diff or diff+1
   else count = (diff/2)+1;

*/
