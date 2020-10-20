class Solution {
    public int findDuplicate(int[] nums) {
        int turtle = nums[0];
        int rabbit = nums[0];

        // find intersection point
        while (true) {
            turtle = nums[turtle]; // 1 step at a time
            rabbit = nums[nums[rabbit]];  // 2 steps at a time
            if (turtle == rabbit){
                break; // found the intersection point (halfway at the cycle
            }

        }

        // go into second phase
        // both the turle and rabbit will be now at the same advantage 1 step at the time
        // turle will start at the beginning
        // rabbit will start from the intersection where they met
        turtle = nums[0];
        while ( turtle != rabbit ){
            turtle = nums[turtle];
            rabbit = nums[rabbit];

        }
        return rabbit;
        
    }
}