/*
Probelem Statement:

There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.
The game ends when there is only one stone remaining. Alice's is initially zero.
Return the maximum score that Alice can obtain.

Approach: Recursion + Dynamic Programming

- We will need two pointers do indicate our current range of numbers that we can split
- After the split, the two rows should not be empty
- We will discard the row with the larger sum
- What if both of the rows have the same sum?
- We will want to pick the row that will give us a higher score
- We will need a quick way to find the sum within a range of indices
- We can create a prefix sum array to quickly retrieve the sum within 2 indices

*/
class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& arr,int start,int end,int sum){
        if(start>=end){return 0;}
        if(dp[start][end]!=-1){return dp[start][end];} 
        int maxi =0,add=0;
        for(int i=start;i<=end;i++){
            add += arr[i];
            if(add==sum-add){
                maxi = max(maxi,max(add + solve(arr,start,i,add),sum-add + solve(arr,i+1,end,add))); // When the sum of both row are equal , we can go anyways.
            }
            else if(add<sum-add){
                maxi = max(maxi,add + solve(arr,start,i,add)); // when sum of second row is maximum
            }
            else maxi = max(maxi,sum-add+solve(arr,i+1,end,sum - add)); // when sum of first row is maximum
        }
        return dp[start][end] = maxi;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int i=0,n = stoneValue.size(),sum=0;
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++){ 
            sum += stoneValue[i];
        }
        return solve(stoneValue,0,n-1,sum);
    }
};
