//Given an array A of integers, return true if and only if it is a valid mountain array.
//Runtime beats 82.32% of cpp submission
//Find the peak(largest number), check whether it is strictly decreasing/increasing from the peak

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int j=0,k=0;
        int large=0;
            if(A.size()<3)
                return false;

            for(int i=0;i<A.size()-1;i++){
                if(A[i]<A[i+1])
                    large=i+1;
            }
            if(large==0 ||large==A.size()-1)
                return false;

            while(k<large){
                if(A[k]>=A[k+1])
                    return false;
                k++;
            }
            j=large;
            while(j<A.size()-1){
                if(A[j]<=A[j+1])
                    return false;
                j++;
            }

            return true;

    }
};
