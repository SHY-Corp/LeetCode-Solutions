int maximalNetworkRank(int n, vector<vector<int>>& roads) {
     
        vector<int> vec(n);     // will keep sum of how many roads (incoming/outgoing) for all cities
        vector<vector<int>> rdNum(n, vector<int>(n,0));     //matrix values will set to 1 if the pair of cities has road between them
        int i,j, sum=0, maxSum = INT_MIN;
        for(i=0; i<roads.size(); i++)
        {
            vec[roads[i][0]] = vec[roads[i][0]]+1;      // no. of roads (incoming/outgoing) for a particular city
            vec[roads[i][1]] = vec[roads[i][1]]+1;
            rdNum[roads[i][0]][roads[i][1]] =1;     //matrix values for pair of city set to 1
            rdNum[roads[i][1]][roads[i][0]] =1;     //set 1 for both roads [ai,bi]
        }
        
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                sum = vec[i]+vec[j];    //sum incoming and outgoing roads
                if(rdNum[i][j] == 1)        //if those pairs have direct road, subtract 1 to count only 1 road and not 2 for that pair
                    sum = sum-1;
                maxSum = max(maxSum, sum);  // keep track of maximum network rank
            }
        } 
        return maxSum;
    }
