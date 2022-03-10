class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
     /*   vector<int> temp;
        int sum = 0;
        for(int i=0; i<accounts.size(); i++)
        {
            for(int j=0; j<accounts[i].size(); j++)
            {
                sum = sum + accounts[i][j];
            }
            temp.push_back(sum);
            sum = 0;
        }

        return *max_element(temp.begin(), temp.end());  */

        //better approach than the above(instead of storing it in a vector)
        int sum;
        int maxWealth = INT_MIN;

        //iterating over the grid to find the total amount of money ith customer has summing the j-values
        for(int i=0; i<accounts.size(); i++)
        {
            //initializing it to 0 after calculating the amount for each iteration
            sum = 0;
            for(int j=0; j<accounts[i].size(); j++)
            {
                sum = sum + accounts[i][j];
            }
            //storing the maximum sum in maxWealth
            if(sum>maxWealth)
                maxWealth = sum;
        }
        return maxWealth;
    }
};
