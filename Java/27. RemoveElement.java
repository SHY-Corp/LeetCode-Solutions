class Solution {

    void delElement(int[] arr, int key, int len){
        if(arr.length < len) throw new ArrayIndexOutOfBoundsException("Length is longer than array length");
        if (len - 1 - key >= 0) System.arraycopy(arr, key + 1, arr, key, len - 1 - key);
    }

    public int removeElement(int[] nums, int val) {
        int i = 0;
        int len = nums.length;

        for(int j = 0; j < nums.length; j++){
            if(nums[j] != val) {
                nums[i++] = nums[j];
                len--;
            }
        }
        return nums.length-len;

    }
}
