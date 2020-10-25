class Solution {
public:
    static bool comparator_sort(const vector<int> &x,const vector<int> &y){
        return x[0] < y[0];
    }
    int minRefuelStops(int target, int start_fuel, vector<vector<int>>& stations) {
        if(start_fuel > target)
            return 0;
        int n=stations.size();
        int curr_fuel=start_fuel;
        vector<long long int> dp(n+1 ,0);

        //dp[i] => Max distance that can be travelled with i stops

		dp[0]=curr_fuel;
        sort(stations.begin(),stations.end(),comparator_sort);

        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(dp[j]>=stations[i][0]){
                    dp[j+1]=max(dp[j+1],dp[j]+stations[i][1]);
                }
                else
                    break;
            }
        }
        for(int i=0;i<=n;i++){
            if(dp[i]>=target)
                return i;
        }
        return -1;
    }
};
