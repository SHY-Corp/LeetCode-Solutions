import java.util.*;
class Solution {
    public int heightChecker(int[] heights) {
        int[] sortHeights=new int[heights.length];
        int count=0;
        for(int i=0;i<heights.length;i++){
            sortHeights[i]=heights[i];
        }
        Arrays.sort(sortHeights);
        for(int i=0;i<heights.length;i++){
            
            if(heights[i]!=sortHeights[i]){
                count++;
            }
        }
        return count;
    }
}
