/*
https://leetcode.com/problems/sum-of-even-numbers-after-queries/

We have an array A of integers, and an array queries of queries.

For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].  Then, the answer to the i-th query is the sum of the even values of A.

(Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)

Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.

*/

class Solution {
public:    
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
       int n = A.size(), sum = 0, idx = 0;; 
       vector<int> ret(n, 0);

        for(auto x : A)
            if(!(x&1))
                sum += x;

        for(auto q : queries){

            if(!(A[q[1]]&1))
                sum -= A[q[1]];        

            A[q[1]] += q[0];

            if(!(A[q[1]]&1))
                sum += A[q[1]];        

            ret[idx++] = sum;
        }    

        return ret;        
    }
};