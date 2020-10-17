/*
In this problem, we use a greedy solution.

Let define answer as the sum of costs to all people go to B city, however we need exactly n people in each city. To do that we need change the city of n people. When we change the city of one person we need to update the answer, to do this we'll subtract the value to go to city B and add the value to go to city A, that is, costs [i][0] - costs[i][1].

Now, we need to choose the people that affect more the answer. It's easy to see that it is ever advantageous choose the person with smaller value of costs[i][0] - costs[i][1].

Therefore, we create a array with this values and sort this array and after this we'll pick the n firsts persons in the array.

Let sz = costs.length
Complexity: O(sz log sz)
*/

class Solution {
    public int twoCitySchedCost(int[][] costs) {
        
        int n = costs.length >> 1, answer = 0;

        int[] diffs = new int[costs.length];
        
        for(int i = 0; i < costs.length; i++){
            answer += costs[i][1]; //putting all in city B
            diffs[i] = costs[i][0] - costs[i][1]; // creating the array of differences 
        }
        
        Arrays.sort(diffs); // sorting the array
        
        for(int i = 0; i < n; i++) answer += v[i]; //updating the answer change the city of person.
        
        return answer;
    }
}

