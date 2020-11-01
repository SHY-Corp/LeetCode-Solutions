//890| Find and Replace Pattern
/* Statement:
** You have a list of words and a pattern, and you want to know which words in words matches the pattern.
** A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n=words.size(),i,j,m=pattern.size();
        vector<string> sol;
        for(i=0;i<n;i++){
            map<char,char> m1,m2;
            int flag=1;
            if(words[i].size()==m){
                for(j=0;j<m;j++){
                    if(!m1[words[i][j]])
                        m1[words[i][j]]=pattern[j];
                    if(!m2[pattern[j]])
                        m2[pattern[j]]=words[i][j];
                    if(m1[words[i][j]]!=pattern[j]||m2[pattern[j]]!=words[i][j]){
                        flag=0;
                        break;
                    }
                }
                if(flag)
                    sol.push_back(words[i]);
            }
        }
        return sol;
    }
};

