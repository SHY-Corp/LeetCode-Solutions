/*
This problem is like a sliding window problem(where the sliding window size is 2) and you need to pick up that contiguous
combination, which gives maximum number of fruits for 2 baskets.

I am maintaining a record of tree[i] and their count in a map named basket and maintaining a counter variable initialized as 0
which stores maximum of count and current iteration value for each step. This count updates for each step depending upon the type
of fruit you encounter when you go from left to right. Your final count is the maximum number of fruits you can pick.

The language of this question is sort of confusing. I am providing an example from the Leetcode problem description by changing the
names that are in sync with this problem language.

Example:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

In the input array of fruit, let us assume 0 represents Apple, 1 represents Banana and 2 represents Grape.
This is what my input will now look like:
['Apple', 'Banana', 'Grape', Grape']

-> I have 2 baskets. I start from left, so I will pick the first fruit, i.e. Apple, because both my baskets are empty.
-> I go towards left and pick the 2nd fruit(Banana). So now, both my baskets have ['Apple', 'Banana'], and max count=2;
-> I go more left and see a 3rd type of fruit(Grape), because I have not reached the end of the tree row, I can pick this
   fruit and remove the Apple from 1st basket. My max count is still 2 and now I have ['Banana', 'Grape'] in my 2 baskets each.
-> I go more left and I encounter the 3rd type of fruit once again, which I know exists in one of the baskets, so I pick it. Now
   I have ['Banana', "Grape', 'Grape'] in my baskets and my count is 3.
-> This was the last fruit and my final count is 3. This is the maximum number of fruits I can pick if I go from left to right
   maintaining a continuous iteration.
*/

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        //base condition
        if(tree.empty()) // or n == 0
            return 0;

        map <int, int> basket; //record for each type of fruit
        int n = tree.size();
        int count = 0; //this variable maintains a fruit count at each step as we go from left to right and pick a fruit
        int j=0;   //2nd counter for iterating over tree[i]. This is like your sliding window size. It should be <= i.

        //Iterating over the tree
        for(int i=0; i<n; i++)
        {
            //Incrementing the record by 1 as we encounter a fruit of type i
            basket[tree[i]]++;

            //We only have 2 baskets. If we see a new fruit or a 3rd type of fruit and the 2nd pointer j<=i, we decrement the jth
            //record and check for the base condition of basket[tree[i]] being 0 so that it can be removed from the basket and a
            //new fruit type can be added to the record.
            while(basket.size()>2 && j<=i)
            {
                basket[tree[j]]--;
                if(basket[tree[j]]==0)
                    //While iterating, if you come across a record which is decremented to 0, you remove it.
                    basket.erase(tree[j]);
                //and increment this variable to include the next fruit type in the row.
                j++;
            }
        //Storing the max of count and current number of fruit type that were encountered at one iteration.
        count = max(i-j+1, count);
        }
        return count;
    }
};
