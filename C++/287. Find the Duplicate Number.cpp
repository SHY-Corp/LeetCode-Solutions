class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int a,b,n;
        n = nums.size();
        
 /* I have taken 2 integer variables and I am storing the
    first element of nums in both of them. The idea is to traverse
    the whole array through their indices with the help of 2 
    separate integers(at different paces), much like linked list
    traversal.
 */    
        a = nums[0];
        b = nums[0];
        
/* So now, I move integer 'a' once and integer 'b' twice, storing 
   their value as indices in nums, till they don't collide. The fact
   that 'b' is moving twice as fast as 'a', there will come a point when
   they both collide. Once they do, I come out of the loop and once again
   store the very first value of nums in b. This time however, I will 
   move both 'a' and 'b' at equal speed, i.e., 'b' will be moving at a's pace,
   so when there is a collision(2nd one in this case), their point of collision
   this time will give us the duplicate number, and I can return either of the 
   two integers.
*/      
        do{
            a=nums[a];
            b=nums[nums[b]];
        }while(a!=b);
            
        b=nums[0];
        while(a!=b)
        {
            a=nums[a];
            b=nums[b];
        }
        
        return b;
    }
};

/* What really happened in between collisions: The first collision
   implies that the array has been traversed once when both integers
   were moving at different speeds. The 2nd collision is the point 
   that gives us the index of duplicate value when both the integers
   are moving at the same speed. This is like linked list. You traverse
   once, and then you traverse again to see any anomaly. 
*/