class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
         vector<vector<string>> y;
        
        if(strs.size() == 0) return y;
        
        map<string,vector<string>> dict;
        for(string s: strs)
        {
            string sorted = s;
            sort(sorted.begin(),sorted.end());
            dict[sorted].push_back(s);
        }
        map<string,vector<string>>::iterator o = dict.begin();
        while(o != dict.end())
        {
            y.push_back(o->second);
            o++;
        }
    
        return y;
        
    }
};
