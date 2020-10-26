class Solution {
public:
    int histArea(vector<int> hist)
    {
        
        stack<int> s;
        int n = hist.size();
        int i=0;
        int mxarea = 0;
        while(i<n)
        {
            if(s.empty() || hist[i]>=hist[s.top()])
                s.push(i++);
            else
            {
                int top = s.top();
                s.pop();
                mxarea = max(mxarea,hist[top] * (s.empty()?i:i-s.top()-1));
            }
        }
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            mxarea = max(mxarea,hist[top]*(s.empty()?i:i-s.top()-1));
        }
        return mxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if(r==0) return 0;
        int c = matrix[0].size();
        vector<int> hist(c);
        for(int i = 0;i<c;i++)
        {
            hist[i] = matrix[0][i]-'0';
        }
        int mxarea = 0;
        mxarea = histArea(hist);
        for(int i=1;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]=='0')
                {
                    hist[j] = 0;
                }
                else
                {
                    hist[j]++;
                }
                
            }
            
            mxarea = max(mxarea,histArea(hist));
        }
        
        return mxarea;
    }
};
