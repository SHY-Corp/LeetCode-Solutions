class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        /*I am implementing this using Binary search. We have 2 base conditions
          that if my target < the character at first index and greater than or equal 
          to the last index, then I will return the very first character in this
          array(since, letters wrap around!).
        */
        int n, left, right, mid;
        n=letters.size();
        left = 0;
        right = n-1;
        
        if(target<letters[left]||target>=letters[right])
            return letters[0];

        /* If left+1=right, then I will go into infinite loop(mid=low will run forever),
           so I need a break condition, therefore, left+1 < right satisfies that condition.
        */
        while(left+1!=right)
        {
            mid=(right+left)/2;
            
            if(letters[mid]<=target)
                left=mid;   //first half of the vector, i.e., before mid
            else
                right=mid;  //second half of the vector, i.e., =>mid
        }
        return letters[right]; //returning letters[right] as the target value will still be <=.
    }
};