/*
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
You may return any answer array that satisfies this condition.

Example 1:

    Input: [4,2,5,7]
    Output: [4,5,2,7]
    Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        
        vector<int> B(n,0);
        int j=0,k=1;
        for(int i=0;i<n;i++){
            if(A[i]%2==0){   //Even no.
                B[j]=A[i];
                j+=2;
            }
            
            if(A[i]%2==1){   //Odd no.
                B[k]=A[i];
                k+=2;
            }      
        }

        return B;
    }
};
