class Solution {
    public int[] sortArrayByParity(int[] A) {
        // optimizing                                          
        for (int i = 0, j = 0; i < A.length; i++) {
                if (A[i] % 2 == 0) {
                        int temp = A[j];
                        A[j] = A[i];
                        A[i] = temp;
                        j++;
                }                                                
        }
        return A;
    }
}
