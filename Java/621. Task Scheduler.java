class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq = new int[26];

        int maxFreq = 0;
        for (char task : tasks) {
            ++freq[task - 'A'];
            maxFreq = Integer.max(maxFreq, freq[task - 'A']);
        }

        int numsWithMaxFreq = 0;
        for (int i = 0; i < 26; ++i) {
            if (maxFreq == freq[i])
                ++numsWithMaxFreq;
        }

        // if AAABBBCCDDE, n=3 => ABxxABxxAB is the frame with size 10
        int frameSize = Integer.max(numsWithMaxFreq, n + 1) * (maxFreq - 1) + numsWithMaxFreq;
        int occupied = numsWithMaxFreq * maxFreq;
        int rem = 0;

        for (int i = 0; i < 26; ++i) {
            if (freq[i] == maxFreq)
                continue;
            rem += freq[i];
        }

        return Integer.max(frameSize, occupied + rem);
    }
}