class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>a;
        for(int i=0;i<s.size();i++){
            // cout<<s[i];
            a[s[i]]++;
        }
        priority_queue<pair<int,char>>b;
        for(auto it = a.begin();it!=a.end();it++){
            // cout<<it->first;
            b.push(make_pair(it->second,it->first));
        }
        string ans;
        char x;
        int y;
        cout<<b.size()<<endl;
        while(!b.empty()){
            y = b.top().first;
            x = b.top().second;
            cout<<x<<y;
            for(int j=0;j<y;j++){
                ans.push_back(x);
            }
            b.pop();
        }
        return ans;
    }
};