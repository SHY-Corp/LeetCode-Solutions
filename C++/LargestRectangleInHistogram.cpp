//Problem 84.Largest Rectangle in Histogram

//CODE
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
        int max_area = 0;
		//We maintain a stack which stores the index of the shortest rectangle encountered so far and those of consequent
		//rectangles taller than it. As we encounter shorter rectangles than the tallest rectangle in the stack,  we pop elements
		//to maintain a  stack with indices of rectangles with non-decreasing heights. The key idea is that a rectangle with 
		//height equal to that of the 'minimum encountered so far' can extend into subsequent rectangles. As we pop an 
		//indices from the stack, we need to record the maximum area that a rectangle with the poped rectangle's height could
		//occupy which is simply the index until (not including) i in the for loop till (not including) the previously unpoped 
		//element present in the stack.
        stack<int> s;
        for (int i=0; i<heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int cur_max = s.top();
                s.pop();
                //Add upto previous index -> (i-1) - (the index of the last value we didn't kick out + 1) + 1.
				//If s is empty we are simply considering a recrtangle starting from i=0.
                int area = heights[cur_max] * ((i-1) - ((s.empty()?-1:s.top())+1) + 1);
                max_area = max(area,max_area);
            }
            s.push(i);
        }
        //If the last few values are increasing, we need to remove these values.
        while (!s.empty()) {
            int cur_max = s.top();
            s.pop();
            //Add upto previous index -> (n-1) - (the index of the value we kicked out) + 1.
            int area = heights[cur_max] * ((n-1) - ((s.empty()?-1:s.top())+1) + 1);
            max_area = max(area,max_area);
        }
        
        return max_area;
        
    }
};
