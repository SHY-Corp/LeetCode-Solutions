//Problem Number 35: Search Insert Position

/*Given a sorted array of distinct integers and a target value,
return the index if the target is found. If not,
return the index where it would be if it were inserted in order.*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int ans;
        for(int i=0; i<nums.size(); i++){
            if(nums.at(i)==target || nums.at(i)>target){/*at function Returns a reference to the element at that position  in the vector*/
                ans = i;
                break;
            }
        }
        return ans;
    }
};
