// problem - 1217. Minimum Cost to Move Chips to The Same Position

/*
    We have n chips, where the position of the ith chip is position[i].

    We need to move all the chips to the same position. In one step, we can change 
    the position of the ith chip from position[i] to:
        position[i] + 2 or position[i] - 2 with cost = 0.
        position[i] + 1 or position[i] - 1 with cost = 1.
    
    Return the minimum cost needed to move all the chips to the same position.
*/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0;
        int odd = 0;

        // looping through positions and incrementing odd or even as for thier position
        for(int pos: position) {
            if(pos&1) odd++;
            else even++;   
        }

        if(odd == 0 || even == 0) return 0;
        else if(odd > even) return even;
        else return odd;     
    }
};

// Time Complexity = O(n) Linear Time
// Space Complexity = O(1) Constant Time