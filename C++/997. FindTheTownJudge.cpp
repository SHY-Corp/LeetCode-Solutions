/*
PROBLEM: 

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.

There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2

Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3

*/

/*
Solution:

**Note: "trust" is a pair of vectors. So, each element of the trust vector contains two parts ie., first and second element of
the pair.

We will create two arrays namely frequency array and isVisited array of size N+1 each (since, the indexing is from 1 to N).
1) Frequency array: It records the frequency of the appearance of second element of the pair of trust vector.
2) isVisited array: It records whether an index appears as the first element of the pair of trust vector.

Now, we will traverse the entire trust vector and update the frequency array and isVisited array. 

Now, for a person to be judge of the town:
1) He should not trust anyone. (So, his index should never come as the first element of the pair in the trust vector).
Therefore, the value of the isVisited array should be "false" corrosponding to the index of the judge.

2) Everyone else should trust him. (So, he should be trusted by N-1 people).
Therefore, the value of the Frequency array should be "N-1" corrosponding to the index of the judge.

So, to find the index of the judge, we will run a loop at the end and check if the above two conditions are satisfied or not.
If the above mentioned conditions satisfy for any index, we will return that index as the answer.
Otherwise, we will return -1.	

*/



class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<int> freq(N+1,0);
        vector<bool> isVisited(N+1,false);
        
        int a,b;
        
        for(int i=0;i<trust.size();i++){
            a = trust[i][0];
            b = trust[i][1];
            
            isVisited[a] = true;
            freq[b]++;
        }
        
        for(int i=1;i<N+1;i++){
            if(freq[i] == N-1 && !isVisited[i]){
                return i;
            }
        }
        
        return -1;
    }
};