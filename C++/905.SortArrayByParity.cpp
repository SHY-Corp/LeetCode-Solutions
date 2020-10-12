//Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
//Check if odd, erase it from the array and push the element at the back

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n=A.size();
        int i=0,count=0;
        while(count<n){
            if(A[i]%2!=0){
                A.push_back(A[i]);
                A.erase(A.begin()+i);
            }
            else
                i++;
            count++;
        }
        return A;
    }
};
