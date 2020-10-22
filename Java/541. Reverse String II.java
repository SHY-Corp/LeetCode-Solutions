Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"


The idea here is to increment the loop counter with the gap of 2k,
For each block, the initial k elements are reversed by swapping, keeping the last k elements as it is.
For the last block where the size can be varied, we need to check whether the elements in this block is of atleast k length, if so we reverse using swapping.

Code:

class Solution {
    public String reverseStr(String s, int k) {
        //Converting the string to char array
        char[] array = s.toCharArray();
        //Traversing the array in the blocks of 2k
        for (int indx = 0; indx < array.length; indx += 2 * k) {
            int i = indx;
            //For each block to reverse we initialize the pointer at either ends (i.e the first element and the kth element of the block)
            int j = Math.min(indx + k - 1, array.length - 1);
            //We reverse by swaping the elements.
            while (i < j) {
                char temp = array[i];
                array[i++] = array[j];
                array[j--] = temp;
            }
        }
        return new String(array);
    }
}