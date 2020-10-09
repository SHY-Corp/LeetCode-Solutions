/**
    Question 139 Word Break : Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
    Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.
**/

/**
    Approach : Recursive approach -> In this approach we take map to store if that substring exits in dict or not. At first we pass the whole string and check if that string is present in dic or not. If not then we check with each word in dict, any word matching with the substring of s from first so that we can break that string and recursively check for further substring in the word dict and accordingly set the map.
**/    

#include <bits/stdc++.h>
using namespace std;
    
class Solution {
public:
    unordered_map<string,bool> mp;
    
    bool startwith(string s,string t){
        int i=0,j=0;
        if(t.length()>s.length())
            return false;
        
        while(j<t.length()){
            if(s[i]!=t[j]){
                return false;
            }
            i++;
            j++;
        }
        
        return true;
    }
    
    bool wb_utils(string s,vector<string>& wordDict){
        if(s=="")
            return true;
        
        if(mp.find(s)!=mp.end())
            return mp[s];
        
        for(int i=0;i<wordDict.size();i++){
        	
            if(startwith(s,wordDict[i])){
    			//ut<<wordDict[i]<<endl;         
                string nxt = s.substr(wordDict[i].length());
                
                if(wb_utils(nxt,wordDict)){
                    mp[s] = true;
                    return true;
                }
            }
        }
        
        return mp[s] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        //m.insert(make_pair("",1));
        return wb_utils(s,wordDict);
    }
};