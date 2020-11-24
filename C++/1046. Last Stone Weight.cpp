// problem - 1046. Last Stone Weight

/*
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  
Suppose the stones have weights x and y with x <= y.  The result of this smash is:
    > If x == y, both stones are totally destroyed;
    > If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.

At the end, there is at most 1 stone left.  
Return the weight of this stone (or 0 if there are no stones left.)
*/

#include <set>
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];

        // storing all stones in decending order of thier weights
        multiset<int, greater <int>> mset;
        for(int stone: stones) {
            mset.insert(stone);
        }
        
        while(!mset.empty()) {
            // getting the heaviest stone available
            int first = *mset.begin();
            mset.erase(mset.begin());
            
            if(mset.empty()) return first;
            
            // getting the second heaviest stone available
            int second = *mset.begin();
            mset.erase(mset.begin());
            
            // smashing heaviest and second heaviest stones
            int res = abs(first - second);
            // remaining stone after smashing
            if(res != 0) mset.insert(res); 
        }
        
        return 0;
    }
};

// Time Complexity = O(n)
// Space Complexity = O(n) [where n is number of stones given]