//Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, 
//return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.

class Solution {
    vector<string>ans;
public:
    vector<string> maxNumOfSubstrings(string s) {
        ans.clear();
        vector<vector<int>> index(26);
        for(int i=0;i<s.size();i++)
        {
            int pos = s[i]-97;
            if(index[pos].size()==2)
                index[pos][1]=i;
            else
            {
                index[pos].push_back(i);
                index[pos].push_back(i);
            }
        }
        solve(0,s.size()-1, s, index);
        return ans;
    }
    void solve(int start, int end , const string & s, vector<vector<int>>& index)
    {
        char ch = s[start];
        int flag=0;
        for(int i=start;i<=end;i++)
        {
            int val = s[i]-97;
            if(ch!=s[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            ans.push_back(s.substr(start, end-start+1));
            return;
        }
        flag=0;
        for(int i=start;i<=end;i++)
        {
            int val = s[i]-97;
            int spos = index[val][0], epos = index[val][1], cf=0;
            if(spos==i && epos<=end)
            {
                for(int j=i+1;j<=epos;j++)
                {
                    int val = s[j]-97;
                    if(index[val][1]>epos)
                     epos=max(epos,index[val][1]);
                    if(index[val][0]<spos)
                    {cf=1;break;}
                }
                if(!(spos==start && epos==end) && cf==0)
                {
                    solve(spos,epos,s,index);
                    i=epos;
                    flag=1;
                }
                
            }
        }
        if(flag==0)
            ans.push_back(s.substr(start, end-start+1));
        return;
    }
};
