/*Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
Example 1:
Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:
Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:
Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:
Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.*/

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map <string,char> m;
		   unordered_map <char,string> m2;
		vector <string> vec;
		string s="";
		for(auto i:str){
			
			if(i==' '){
					vec.push_back(s);
				s="";
				continue;
			}
				s=s+i;
		}
		   vec.push_back(s);
		if(vec.size()!=pattern.size())
			return false;
		int n=pattern.size();
		for(int i=0;i<n;i++){
			if(m.find(vec[i])!=m.end()){
				if(m[vec[i]]!=pattern[i]){
					return false;
				}
			}
				else if(m2.find(pattern[i]) !=m2.end()){
					if(m2[pattern[i]]!=vec[i])
						return false;
				}
			else{
				m[vec[i]]=pattern[i];
				  m2[pattern[i]]=vec[i];
			}
		}
		return true;
		
		
	}
};
