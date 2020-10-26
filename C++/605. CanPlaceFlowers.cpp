/*
Suppose you have a long flowerbed in which some of the plots are planted and some are not. 
However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty),
and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False

Note:
	The input array won't violate no-adjacent-flowers rule.
	The input array size is in the range of [1, 20000].
	n is a non-negative integer which won't exceed the input array size.
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size(); // stores the size of the flowerbed
        int cnt = 0; // count the number of flowers that can be placed on the flowerbed
        for(int i=0;i<sz;i++){
            if(flowerbed[i] == 0) // you can place if the current place is empty
			{
                bool left = (i>0 && flowerbed[i-1]==0) || (i == 0); // true if the left place is empty or does not exists
                bool right = (i<(sz-1) && flowerbed[i+1]==0) || (i == sz-1); // true if the right place is empty or does not exists
                if(left && right)
                    flowerbed[i] = 1, cnt++;
            }
        }
        return (n<=cnt); // if you can place n flowers, then return true else false
    }
};