class Solution {

    void delElement(int[] arr, int key, int len){
        if(arr.length < len) throw new ArrayIndexOutOfBoundsException("Length is longer than array length"); //if input value is less than array lenght, it will throw ArrayIndexOutOfBoundsException exception
        if (len - 1 - key >= 0) System.arraycopy(arr, key + 1, arr, key, len - 1 - key); //add elements to array
    }

    public int removeElement(int[] nums, int val) {
        int i = 0;              // declaration variable
        int len = nums.length;  //declaration array lenght

        for(int j = 0; j < nums.length; j++){  //go through the array elements with the for loop
            if(nums[j] != val) {       //if statement : actual value of array != input value
                nums[i++] = nums[j];   // compare with other elements of array
                len--;                 //decrement lenght
            }
        }
        return nums.length-len;

    }
}
