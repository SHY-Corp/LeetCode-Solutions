// problem - 1306. Jump Game III

/*
    Given an array of non-negative integers arr, you are initially positioned 
    at start index of the array. When you are at index i, 
    you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

    Notice that you can not jump outside of the array at any time.
*/

class Solution {
public:
    bool canReachHelper(vector<int>& arr, vector<bool>& track, int idx) {
        // if index out of bounds return false
        if(idx > arr.size() or idx < -1) return false;
        // if already visted return false
        if(track[idx] == false) return false;
        // marking as visted
        else track[idx] = false;
        // if target reached
        if(arr[idx] == 0) return true;
        
        // recursing as per the given conditions
        int i1 = idx + arr[idx];
        bool res1 = (i1 < arr.size()) ? canReachHelper(arr, track, i1) : false;
        
        int i2 = idx - arr[idx];
        bool res2 = (i2 > -1) ? canReachHelper(arr, track, i2) : false;
        
        return res1 or res2;
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        // tracks if already visted or not (if already visted = false, if not visted = true)
        vector<bool> track(n, true);
        
        return canReachHelper(arr, track, start);
    }
};

// Time Complexity = O(N)
// Space Complexity = O(N) [where N is the size(length) of the given array]