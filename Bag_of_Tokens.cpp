class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
       int i=0, j= tokens.size()-1;
       int maxScore=0, secondScore=0;
            sort(tokens.begin(), tokens.end());
            while(i<=j){
                    if(P >= tokens[i]){
                            secondScore++;
                            maxScore = max(maxScore, secondScore);
                            P-=tokens[i];
                            i++;
                    }
                    else if(secondScore>0){
                            secondScore--;
                            P+=tokens[j];
                            j--;
                    }
                    else return maxScore; 
            }
            return maxScore;
    }
};