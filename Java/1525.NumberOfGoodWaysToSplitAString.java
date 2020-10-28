class Solution {
  public int numSplits(String s) {
    int[] leftHalf = new int[26];
    int[] rightHalf = new int[26];

    for (char c : s.toCharArray()) {
      ++rightHalf[c - 'a'];
    }

    int count = 0;
    for (int i = 0; i < s.length(); ++i) {
      char ch = s.charAt(i);
      ++leftHalf[ch - 'a'];
      --rightHalf[ch - 'a'];

      if (isGoodSplit(leftHalf, rightHalf))
        ++count;
    }

    return count;
  }

  private static boolean isGoodSplit(int[] lh, int[] rh) {
    int lDistinct = 0, rDistinct = 0;
    for (int i = 0; i < 26; ++i) {
      lDistinct += lh[i] > 0 ? 1 : 0;
      rDistinct += rh[i] > 0 ? 1 : 0;
    }

    return lDistinct == rDistinct;
  }
}