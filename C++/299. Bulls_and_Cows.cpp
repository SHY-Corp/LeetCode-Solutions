/*
299. Bulls and Cows
You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

    The number of "bulls", which are digits in the guess that are in the correct position.
    The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.

Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.
  
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        
        int cnt=0, cnt2=0;
        set<int> st;
        unordered_map<char, int> mp;
        for(int i=0;i<secret.length();i++){
            if(secret[i]!=guess[i]) mp[secret[i]]++;
        }
        
        for(int i=0;i<guess.length();i++){
            if(secret[i]==guess[i]){
                cnt++;
            }else{
                if(mp[guess[i]] >0){
                    cnt2++;
                    mp[guess[i]]--;
                }
            }
        }
        string ans = to_string(cnt) +"A" + to_string(cnt2)+"B";
        return ans;
        
    }
};