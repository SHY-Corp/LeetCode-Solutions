class Solution {
    public int largestRectangleArea(int[] heights) {
        if(heights.length == 0){
            return 0;
        }
        int[] nser = new int[heights.length];
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
        
        int[] nsel = new int[heights.length];
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
