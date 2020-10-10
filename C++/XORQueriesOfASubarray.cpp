class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans; 
        vector<int> seive(n,0);
        seive[0] = arr[0];
        
        for(int i = 1;i<n;i++){
            seive[i] = arr[i]^seive[i-1];     //pre-processing
        }
        
        for(vector<int> qry : queries){
            if(qry[0] == 0) ans.push_back(seive[qry[1]]);
            else ans.push_back(seive[qry[0]-1]^seive[qry[1]]);
        }
        return ans;
        
        
    }
};
