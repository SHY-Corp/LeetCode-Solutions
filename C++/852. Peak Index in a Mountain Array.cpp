// Given a mountain array we have to return index of any peak
// Mountain array is strictly increasing sequence combined with strictly decreasing sequence of integers and is greater than 3.
// Runtime beats 74.06% of cpp submissions and is the intended solution


// Key is to use binary search to find the index of positive integer. 

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low)/2;
            
            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
};