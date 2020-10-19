/*
 * Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], 
 * for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). 
 * Return an array containing the result for the given queries.
 * 
 * Example 1:
 * Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
 * Output: [2,7,14,8] 
 * Explanation: 
 * The binary representation of the elements in the array are:
 * 1 = 0001 
 * 3 = 0011 
 * 4 = 0100 
 * 8 = 1000 
 * The XOR values for queries are:
 * [0,1] = 1 xor 3 = 2 
 * [1,2] = 3 xor 4 = 7 
 * [0,3] = 1 xor 3 xor 4 xor 8 = 14 
 * [3,3] = 8
 */
 
class Solution {

    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] xor = new int[queries.length];
        int[] prefix = new int[arr.length];
        prefix[0] = arr[0];
        for(int i = 1; i < prefix.length; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }
        
        for(int i = 0; i < queries.length; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if(l == 0)
                xor[i] = prefix[r];
            else
                xor[i] = prefix[r] ^ prefix[l - 1];
        }
        return xor;
    }
}

/*
* Solution Explanation/Approach:
* We are maintaining a prefix array, prefix[i] denoting XOR of all elements from 0 to i.
* 
* We are using the below property of XOR:
* 1. 0 ^ A = A
* 2. A ^ A = 0
* 3. Ordering of XOR doesn't matter i.e. 1^2^3 = 1^3^2.
* 
* So let's arr = [1,3,4,8] and query = [1,2] i.e. we need to find 3^4. 
* This can be written as (3^4) ^ 0 (using property 1) = (3^4) ^ (1) ^ (1) (using property 2) = (1^3^4) ^ (1) (using property 3)
* And this is nothing but prefix[r] ^ prefix[l - 1].
*/
