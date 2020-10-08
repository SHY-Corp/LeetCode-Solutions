class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new ArrayList<>();
        if (nums == null || nums.length == 0)
            return result;

        int cand1 = 0, cand2 = 0;

        int count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == cand1) {
                count1 ++;
                continue;
            }

            if (num == cand2) {
                count2 ++;
                continue;
            }

            if (count1 == 0) {
                cand1 = num;
                count1 = 1;
                continue;
            }

            if (count2 == 0) {
                cand2 = num;
                count2 = 1;
                continue;
            }

            count1 --;
            count2 --;

        }

        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == cand1) {
                count1 ++;
            } else if (num == cand2) {
                count2 ++;
            }
        }

        if (count1 > nums.length / 3)
            result.add(cand1);

        if (count2 > nums.length / 3)
            result.add(cand2);

        return result;
    }
}