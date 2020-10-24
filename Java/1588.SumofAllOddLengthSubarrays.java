class Solution {
    public int sumOddLengthSubarrays(int[] A) {
        int ans = 0, n = A.length;
        for (int i = 0; i < n; i++) {
            ans = ans + ((i + 1) * (n - i) + 1) / 2 * A[i];
        }
        return ans;
    }
}