class Solution {
  public int closestToTarget(int[] arr, int target) {
    int[] bits = new int[32];
    int p1 = 0, p2 = arr.length - 1;
    int minDiff = Integer.MAX_VALUE;
    int currVal = arr[0];

    for (int i = 0; i < arr.length; ++i) {
      bits = bitCountUpdate(bits, arr[i], 1);
      currVal &= arr[i];
    }

    while (p1 < p2) {
      minDiff = Integer.min(minDiff, Math.abs(currVal - target));

      int[] bitsP1 = bitCountUpdate(bits, arr[p1], -1);
      int[] bitsP2 = bitCountUpdate(bits, arr[p2], -1);

      int valP1 = bitsToValue(bitsP1, p2 - p1);
      int valP2 = bitsToValue(bitsP2, p2 - p1);

      if (Math.abs(valP1 - target) < Math.abs(valP2 - target)) {
        ++p1;
        currVal = valP1;
        bits = bitsP1;
      } else {
        --p2;
        currVal = valP2;
        bits = bitsP2;
      }
    }

    // checking for single values
    for (int num : arr)
      minDiff = Integer.min(minDiff, Math.abs(num - target));

    return minDiff;
  }

  private int[] bitCountUpdate(int[] bits, int num, int update) {
    int[] newBitArray = new int[32];
    for (int i = 0; i < 32; ++i)
      newBitArray[31 - i] = bits[31 - i] + update * ((num >> i) & 1);
    return newBitArray;
  }

  private int bitsToValue(int[] bits, int diff) {
    int value = 0;
    for (int i = 31; i >= 0; --i) {
      if (bits[i] == diff)
        value |= 1 << (31 - i);
    }
    return value;
  }
}