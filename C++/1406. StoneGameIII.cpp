/*

Problem Statement : Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2 or 3 stones from the first remaining stones in the row.
The score of each player is the sum of values of the stones taken. The score of each player is 0 initially.
The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.
Assume Alice and Bob play optimally.
Return "Alice" if Alice will win, "Bob" if Bob will win or "Tie" if they end the game with the same score.

Approach:
- Lets first implement the recursive approach
        - For each of the 'start' index
            - We will have up to 3 choices
                - We can pick 1,2 or 3 numbers
            - Since, each player is playing optimally
                - We will want to pick the choice that will give us the highest score
    - We will keep track of a 'totalScore' using dp[i]
        - The points that 'Alice' get will increment the 'totalScore'
        - The points that 'Bob' gets will decrement the 'totalScore'
        - Alice will want the total score to be as positive as possible
        - Bob will want the total score to be as negative as possible
    - If the final total score is greater than 0
        - Then Alice wins
    - If the final total score is less than 0
        - Then Bob wins
    - Else, it will be a tie

*/
class Solution {
public:
    
    int solve(vector<int> &arr,int i,vector<int>& dp){
        if(i>=arr.size()){return 0;}
        if(dp[i]!=INT_MAX){return dp[i];}
        int sum=arr[i];
        int val = sum - solve(arr,i+1,dp);
        for(int j= i+1;j<min(i+3,(int)arr.size());++j){
            sum += arr[j];
            val = max(val,sum - solve(arr,j+1,dp));
        }
        return dp[i] = val;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int x= 0;
        vector<int> dp((int)stoneValue.size()+1,INT_MAX);
        x = solve(stoneValue,0,dp);
        if(x>0){return "Alice";}
        else if(x<0){return "Bob";}
        else return "Tie";
    }
};
