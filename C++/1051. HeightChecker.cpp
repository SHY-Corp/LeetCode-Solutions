//Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.
//Make a copy of the array, sort the copy and comapre it with the actual array

class Solution {
public:
        int heightChecker(vector<int>& heights) {
        if (heights.size()<2)
            return 0;
        
        vector<int> map(101,0);
        
        for (int h:heights)
            map[h]++;
        
        int res = 0;
        int h_ptr = 1;
        
        for (int h:heights)
        {
            while (map[h_ptr]==0)
                h_ptr++;
            
            if (h != h_ptr)
                res++;
            
            map[h_ptr]--;
        }
        
        return res;
    }
};
