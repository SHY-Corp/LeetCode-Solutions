/*
    Problem Statement:
    The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
    Given an integer n, return the number of distinct solutions to the n-queens puzzle.

    Problem Link:
    https://leetcode.com/problems/n-queens-ii/

    Approach:
    Basic Recursive Solution
*/

class Solution {
public:
     int ans = 0;
    int N;
    void doIt(vector<int>&x,int col){
        if(col==N){
            ans++;
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
    
    int totalNQueens(int n) {
        N = n;
        vector<int> x(n,-1);
        doIt(x,0);    
        
        return ans;
    }
};