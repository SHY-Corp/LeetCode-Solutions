/*
This problem can be solved in the following steps:
0- create an empty list called history to hold the generated numbers
1- separate the number at hand to digits (EX: 439 -> {4,3,9})
2- add the squares of the digits obtained from the first step. {EX: 4^2 + 3^2 + 9^2}
3- If the result in found in "history" return False, else: add it to "history" and return to step 1
*/

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<int> history;
    vector<int> separate(int n){
        vector<int> v;
        for(; n; n/=10) v.push_back(n%10);
        return v;
    }
    int add(vector<int> v){
        int result = 0;
        for (int a : v) result += (a*a);
        return result ;
    }
    bool check(int n){return n==1;}
    bool in_history(int n){
        for(int a : history) if(n==a) return true;
        return false;
    }
    bool isHappy(int n) {
        
        while(true){
            vector<int> sep = separate(n);
            n = add(sep);
            if (in_history(n)) return false;
            else{
                history.push_back(n);
                if(check(n)) return true;
            }
        }
    }
};
