// Word Ladder
/**
Problem - 
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
**/

/**
Approach:
This is a search problem, the key ide is to make the graph and use bredth first search to find the shortest distance from starting word to required word.
**/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, list<string> > l;
        
        // Preprocessing Step            
        for(auto word: wordList){ // to make graph
            for(int i = 0; i<word.size(); i++){
                string temp = word;
                temp[i] = '*';
                if(l.find(temp) == l.end()){
                    list<string> a;
                    a.push_back(word);
                    l[temp] = a;
                }
                else{
                    l[temp].push_back(word);
                }
            }
        }
        
        // Search for shortest path
        queue<string> q;
        queue<int> dist;
        
        q.push(beginWord);
        dist.push(1);
        
        unordered_map<string, bool> vis;
        
        for(auto word: wordList){
            vis[word] = false;
        }
        
        vis[beginWord] = true;
        
        int ans = 0;
        
        while(!q.empty()){
            string u = q.front(); q.pop();
            
            int d = dist.front(); dist.pop();
            
            //cout<<u<<" "<<d<<endl;
            
            for(int i = 0; i<u.size(); i++){ // generating intermediate words
                string temp = u;
                
                temp[i] = '*';
                
                for(auto v: l[temp]){ // finding neighbours for temp
                    if(v == endWord){
                        ans = d + 1;
                        return ans;
                    }
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                        dist.push(d+1);
                    }
                }
                
            }
            
        }
        
        
        return ans;
    }
};