//Return a string of all teams sorted by the ranking system.

class Solution {
    struct group {
        char c;
        map<int, int>rank;
        int len;
    };
    
    struct compare {
        bool operator()(struct group g1, struct group g2) {   
            for (int i = 0; i < g1.len; i++) {
                if (g1.rank[i] == g2.rank[i])
                    continue;
                else if (g1.rank[i] < g2.rank[i])
                    return true;
                else
                    return false;
            }
            return g1.c > g2.c;
        }
    };
public:
    string rankTeams(vector<string>& votes) {
        
        int n = votes.size();
        if (!n) return "";
        
        unordered_map<char, map<int, int>>hm;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < votes[i].length(); j++) {
                hm[votes[i][j]-'A'][j]++;
            }
        }
        
        priority_queue<struct group, vector<struct group>, compare>pq;
        for (int i = 0; i < votes[0].length(); i++) {
            struct group g;
            g.c = votes[0][i];
            g.rank = hm[votes[0][i]-'A'];
            g.len = votes[0].length();
            pq.push(g);
        }  
        
        string ans;
        while (!pq.empty()) {
            struct group g = pq.top();
            pq.pop();
            ans += g.c;
        }
        
        return ans;
    }
};
