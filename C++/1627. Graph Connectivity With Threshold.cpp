/**
* link: https://leetcode.com/problems/graph-connectivity-with-threshold/
* Problem description:
* Given a graph with n cities
* two cities x and y are directly connected if
* x and y share a common divisor strictly greater than
* some threshold
* the problem is to answer queries of the type is city a connected to b
* given all conditions already mentioned
* Don't forget cities may be connected but not directly
*/
class Solution {
public:

    //vector where we will store the dad of each node
    vector<int> UF;

    //search for the dad of a given node
    int search(int x){
        return UF[x] == x? x : (UF[x] = search(UF[x]));
    }

    //connect to nodes to belong to the same set
    void connect(int x, int y){
        int dadX = search(x), dadY = search(y);
        if(dadX != dadY)
            UF[dadX] = dadY;
    }


    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        int sz = queries.size();

        UF.resize(n+1);
        //initialize the parent's node to itself
        for(int i = 0; i <= n;++i)
            UF[i] = i;

        //sieve modification to not over count values
        //we one loop from threshold + 1 because those are the values that
        //determine if two nodes are connected
        vector<bool> seen(n+1,0);
        for(int i = threshold+1;i <= n;++i){
            if(!seen[i]){
                for(int j = i+i; j <= n;j +=i){
                    connect(i,j);
                    seen[j] = 1;
                }
            }
        }

        vector<bool> answer(sz);
        for(int i = 0; i < sz;++i){
            int va1 = queries[i][0], va2 = queries[i][1];
            int dad1 = search(va1), dad2 = search(va2);
            answer[i] = (dad1 == dad2);
        }
        return answer;
    }
};
