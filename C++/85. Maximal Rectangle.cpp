class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // return 0 if matrix is empty
        if(matrix.size()==0)
            return 0;
        int m,n;
        m = matrix.size();
        n = matrix[0].size();
        int a[m][n];
        // create histograms of 1's
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0)
                {
                    a[i][j] = (matrix[i][j]=='0')?0:1;
                }
                else{
                    a[i][j] = (matrix[i][j]=='0')?0:(a[i-1][j]+1);
                }
            }
        }
        stack<int> s;
        int mx = -1;
        // find out largest area of histogram for each row
        for(int i=0;i<m;i++){
            while(!s.empty())
                s.pop();
            for(int j=0;j<n;j++){
                if(s.empty())
                    s.push(j);
                else{
                    while(!s.empty()&&a[i][s.top()]>=a[i][j]){
                        int k = s.top();
                        s.pop();
                        int l = (s.empty())?-1:s.top();
                        mx = max(mx,(j-l-1)*a[i][k]);
                    }
                    s.push(j);
                }
            }
            while(!s.empty()){
                int k = s.top();
                s.pop();
                int l = (s.empty())?-1:s.top();
                mx = max(mx,(n-l-1)*a[i][k]);
            }
        }
        return mx;
    }
};