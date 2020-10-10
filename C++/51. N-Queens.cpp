/*
    Problem Statement:
    Given an integer n, return all distinct solutions to the n-queens puzzle.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
    
    Problem Link:
    https://leetcode.com/problems/n-queens/

    Approach:
    Basic Recursive solution.
*/

class Solution {
public:
    vector<string> t;
    vector<vector<int>> correct;
    int N;
    void doIt(vector<int>&x,int col){
        if(col==N){
            correct.push_back(x);
            return;
        }
        set<int> cnt,cnt1,cnt2;
        for(int i = 0;i<col;i++) cnt.insert(x[i]);
        for(int i = 0;i<col;i++) cnt1.insert(i+x[i]);
        for(int i = 0;i<col;i++) cnt2.insert(i-x[i]);
        for(int i = 0;i<N;i++){
            if(cnt.find(i)==cnt.end() && cnt1.find(i+col)==cnt1.end() && cnt2.find(col-i)==cnt2.end()){
                x[col] = i;
                doIt(x,col+1);
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string temp = "";
        N = n;
        for(int i = 0;i<n;i++) temp+=".";
        for(int i = 0;i<n;i++) t.push_back(temp);
        vector<int> x(n,-1);
        doIt(x,0);    
        vector<vector<string>> ans;
        for(auto i: correct){
            for(auto j: i) cout<<j<<" ";
            cout<<endl;
        }
        for(auto i: correct){
            vector<string> cp = t;
            for(int j=0;j<n;j++){
                cp[j][i[j]]='Q';
            }
            ans.push_back(cp);
        }
        return ans;
    }
};