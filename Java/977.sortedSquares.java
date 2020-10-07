class Solution {
    public int[] sortedSquares(int[] A) {
                int count = 0;
                int[] squared = new int[A.length];
                for (int i = 0; i < A.length; i++) {
                        squared[i] = A[i] * A[i];
                }
                Arrays.sort(squared);
                        return squared;
        }
}

