public class Solution {
    public String longestPalindrome(String s) {
        if (s.equals("")) return s;
        boolean[][] dp = new boolean[s.length()][s.length()];
        int res = 0, start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j >= 0; j--) {
                if (i == j) dp[i][j] = true;
                else if (j + 1 == i && s.charAt(j) == s.charAt(i)) dp[i][j] = true;
                else if (dp[i - 1][j + 1] && s.charAt(i) == s.charAt(j)) dp[i][j] = true;
                if (dp[i][j]) {
                    if (i - j + 1 > res) {
                        res = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substring(start, end + 1);
    }
}

public class Solution {
    public String longestPalindrome(String s) {

        char[] S = s.toCharArray();

        if (S.length == 0) return "";

        boolean[][] P = new boolean[S.length][S.length];

        int maxi = 0;
        int maxlen = 1;

        // len 1
        Arrays.fill(P[1 - 1], true);

        // len 2
        for (int i = 0; i < S.length - 1; i++) {
            if (S[i] == S[i + 2 - 1]) {
                P[2 - 1][i] = true;
                maxi = i;
                maxlen = 2;
            }
        }

        // len 3 to max
        for (int len = 3; len <= S.length; len++) {

            for (int i = 0; i < S.length - (len - 1); i++) {

                if (P[len - 1 - 2][i + 1] && S[i] == S[i + len - 1]) {
                    P[len - 1][i] = true;
                    maxi = i;
                    maxlen = len;
                }
            }
        }

        return s.substring(maxi, maxi + maxlen);
    }
}
