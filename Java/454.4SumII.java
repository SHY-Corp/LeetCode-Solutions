import java.util.ArrayList;

class Solution {

    /**
     * The goal is to find the count of all options where A[i] + B[j] + C[k] + D[l] = 0
     * 
     * We can now change this to:
     * A[i] + B[j] = - C[k] - D[l]
     * 
     * Which equals:
     * A[i] + B[j] = -( C[k] + D[l] )
     * 
     * or:
     * - (A[i] + B[j]) = C[k] + D[l]
     * 
     * Now we need to compute all possible sums of A,B and C,D and count equals.
     * 
     * @param A
     * @param B
     * @param C
     * @param D
     * @return
     */
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int length = A.length;

        if (length == 0) 
            return 0;

        ArrayList<Integer> sumsAB = new ArrayList<Integer>();
        ArrayList<Integer> freqAB = new ArrayList<Integer>();
        for (int indexA = 0; indexA < length; indexA++) {
            for (int indexB = 0; indexB < length; indexB++) {
                int tmpSum = A[indexA] + B[indexB];

                if (!sumsAB.contains(tmpSum)) {
                    sumsAB.add(0, tmpSum);
                    freqAB.add(0, 1);
                }else{
                    int indexFreq = sumsAB.indexOf(tmpSum);
                    freqAB.set(indexFreq, freqAB.get(indexFreq) + 1);
                }
            }
        }

        int output = 0;
        for (int indexC = 0; indexC < length; indexC++) {
            for (int indexD = 0; indexD < length; indexD++) {
                int tmpSum = C[indexC] + D[indexD];

                if (sumsAB.contains(-tmpSum)) {
                    int indexFreq = sumsAB.indexOf(-tmpSum);
                    output += freqAB.get(indexFreq);
                }
            }
        }

        return output;
    }
}