// Explaination - for any index i we will take help of array nser and array nsel to find the next smaller element to the right and next smaller element to the left
// respectively. One we get those tho value for a particular index i, we will find the width as nser[i]-nsel[i]-1; Since we have the height already as heights[i]
// widht, we can find the area;
// Prerequisite - Next greater/smaller element on the left/right;
class Solution {
    public int largestRectangleArea(int[] heights) {
        if(heights.length == 0){
            return 0;
        }
        int[] nser = new int[heights.length]; // array contains next smaller element to the right
        Stack<Integer> st = new Stack<>();
        
        st.push(heights.length-1);
        nser[heights.length-1] = heights.length;
        
        for(int i=heights.length-2; i>=0; i--){
            while(st.size()>0 && heights[i]<=heights[st.peek()]){
                st.pop();
            }
            
            if(st.size() == 0){
                nser[i] = heights.length;
            }else{
                nser[i] = st.peek();
            }
            st.push(i);
        }
        
        int[] nsel = new int[heights.length]; // array contains next smaller element to the left
        st = new Stack<>();
        
        st.push(0);
        nsel[0] = -1;
        
        for(int i=1; i<heights.length; i++){
            while(st.size()>0 && heights[i]<=heights[st.peek()]){
                st.pop();
            }
            
            if(st.size() == 0){
                nsel[i] = -1;
            }else{
                nsel[i] = st.peek();
            }
            st.push(i);
        }
        
        int maxArea = 0;
        for(int i=0; i<heights.length; i++){
            int width = nser[i]-nsel[i]-1;
            int area = width*heights[i];
            if(area>maxArea){
                maxArea = area;
            }
        }
        
        return maxArea;
    }
}
