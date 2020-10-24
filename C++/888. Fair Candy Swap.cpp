class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int suma=0,sumb=0;
    vector<int> ans;
    map<int,int> m;
    for(int i=0;i<A.size();i++){
        suma+=A[i];
    }
    for(int i=0;i<B.size();i++){
        sumb+=B[i];
        m[B[i]]++;
    }
    for(auto y : A){
        int a=y+(sumb-suma)/2;
        if(m[a]!=0){
            ans.push_back(y);
            ans.push_back(a);
            break;
        }
    }
    return ans;
}
};
