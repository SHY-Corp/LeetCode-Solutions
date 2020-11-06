class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int i, n;
        n=A.size()-1;

        /*I have initialized 2 integer values to 0.
          They were like a counter for increasing
          and decreasing values in our array.
        */

        int inc=0;
        int dec=0;
         /* Traversing the array using for loop and
            comparing the adjacent values to check their
            pattern. If there is an increasing order, the
            inc count increments, if there is a decreasing
            order, the dec count increments.
         */

        for(i=0; i<n; ++i)
        {
            if(A[i]<=A[i+1])
            {
                inc++;
            }
            if(A[i]>=A[i+1])
            {
                dec++;
            }

        }

        /*Eventually we use OR function to determine
         the outcome. If either of the inc or dec equals
         the array size, then it implies the array is monotonic!
         */

        if ((inc==n)||(dec==n))
            return true;
        return false;
    }
};
