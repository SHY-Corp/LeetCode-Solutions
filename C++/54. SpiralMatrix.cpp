class Solution {
public:
    vector<int>spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int r=matrix.size();
        if(r==0)
            return ans;
        int c=matrix[0].size();

        if((c==0))
            return ans;
        int rowst=0;
        int colst=0;
        int rowend=r-1;
        int colend=c-1;
        while(rowst<=rowend&&colst<=colend)
        {
            for(int i=colst;i<=colend;i++)
            {
                ans.push_back(matrix[rowst][i]);
            }
            rowst++;
            for(int i=rowst;i<=rowend;i++)
            {
                ans.push_back(matrix[i][colend]);
            }
            colend--;
            if(rowst<=rowend)
            {
                for(int i=colend;i>=colst;i--)
                    ans.push_back(matrix[rowend][i]);
            }
            rowend--;
            if(colst<=colend)
            {
                for(int i=rowend;i>=rowst;i--)
                    ans.push_back(matrix[i][colst]);
            }
            colst++;
        }
        return ans;
    }
};
