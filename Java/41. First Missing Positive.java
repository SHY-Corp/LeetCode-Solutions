/*The problem gives an unsorted integer array
 * We have to find the first missing positive integer
 * The problem requires that the runtime should be within O(n) and uses constant space. 
 * 
 */

public class Solution {
    public int firstMissingPositive(int[] A) {
        if (A == null || A.length == 0) {
            return 1;
        }
        int n = A.length;
        int i = 0;
        while (i < n) {
            if (A[i] != i + 1 && A[i] >= 1 && A[i] <= n && A[i] != A[A[i] - 1]) {
                swap(A, i, A[i] - 1);
            } else {
                i++;
            }
        }
         
        for (i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
         
        return A[n - 1] + 1;
    }
     
    private void swap(int[] A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}
