class Solution {
public:
    vector<int> countBits(int num) {
        int c=0;
        vector<int>v;
        for(int i=0;i<=num;i++){
            int n=i;
            while(n>0){
                c++;
                n=n&(n-1);
            }
            v.push_back(c);
            c=0;
        }
        
        return v;
    }
    
};
