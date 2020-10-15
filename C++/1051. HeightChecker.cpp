//Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.
//Make a copy of the array, sort the copy and comapre it with the actual array

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>arr;
        int count=0;
        int n=heights.size();
        arr.assign(heights.begin(),heights.end());
        sort(heights.begin(),heights.end());
        for(int i=0;i<n;i++){
            if(arr[i]!=heights[i])
                count++;
        }
        return count;
    }
};
