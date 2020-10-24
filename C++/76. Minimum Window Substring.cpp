/*

PROBLEM :

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.




APPROACH :

1)Store the occurrence of characters of the given pattern in a hash_pat[].
2)Start matching the characters of pattern with the characters of string i.e. increment count if a character matches.
3)Check if (count == length of pattern ) this means a window is found.
4)If such window found, try to minimize it by removing extra characters from the beginning of the current window.
5)Update min_length.
6)Print the minimum length window.




*/



//CODE

class Solution {
public:
    string minWindow(string s, string t) {
    string str,pat;
	str = s;
    pat = t;
    
	int l1 = str.length();
	int l2 = pat.length();
	int hash_str[256] = {0};
	int hash_pat[256] = {0};
	for(int i = 0;i < l2; i++){
		hash_pat[pat[i]]++;
	}
	int start = 0, start_idx = -1,min_len = INT_MAX,count=0,leng;
	for(int i = 0;i<l1;i++){
		hash_str[str[i]]++;
		if(hash_pat[str[i]]!=0 && hash_str[str[i]]<=hash_pat[str[i]]){
			count++;
		}
		if(count == l2){
			while(hash_str[str[start]]>hash_pat[str[start]]){
				
					hash_str[str[start]]--;
			        start++;

			}
		
		leng = i-start+1;
		if(leng<min_len){
			min_len = leng;
			start_idx = start;
		}

	}
	}
	if(start_idx == -1){
		return "";
	}
	else{
        string st = str.substr(start_idx,min_len);
		return st;
	}



        
    }
};