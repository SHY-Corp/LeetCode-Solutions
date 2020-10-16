class Solution {
public:
    

    
    int maxSumSubmatrix(vector<vector<int>>& a, int k) 
    {
        int n=a.size();
        int m =a[0].size();
        int ans= INT_MIN;
        
        for(int start = 0; start < m;start++)
        {
            vector<int>sum(n,0);
            
            for(int end=start; end<m;end++)
            {
                int cum=0;
                set<int> st{0};
                
                for(int i=0;i<n;i++)
                {
                    sum[i] += a[i][end];
                    cum += sum[i];
                    
                    auto it = st.lower_bound(cum-k);
                    
                    if(it != st.end())
                        ans = max(ans, cum - *it);
                    
                    st.insert(cum);
                    
                }
                
                
            }
        }
        
        return ans;
    }
    
};