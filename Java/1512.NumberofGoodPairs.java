class Solution {
    public int numIdenticalPairs(int[] nums) {
        int cnt[] = new int[101], res = 0;
        for (var n: nums)
            ++cnt[n];
        for (int i = 0; i <= 100; ++i)
            res += cnt[i] * (cnt[i] - 1) / 2;
        return res;     
    }
}