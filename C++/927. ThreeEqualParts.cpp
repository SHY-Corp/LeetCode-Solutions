#define get(upperBound, index) ((index >= upperBound) ? A[index] : 0)

class Solution {
public:
    vector<int> threeEqualParts(vector<int> A) {
        int oneCount = 0;
        int lastOne = -1;
        
        //count the number of ones and where the last one is
        for(int i = 0; i < A.size(); i++){
            if(A[i]){
                oneCount++;
                lastOne = i;
            }
        }
        
        //number of ones is not a multiple of three
        if(oneCount / 3 * 3 != oneCount)
            return {-1, -1};

        //everything is 0
        if(oneCount == 0)
            return {0,2};

        //set i to the index of the (oneCount / 3)th one
        int i = 0;
        int firstOneCount = 0;
        for(; i < A.size(); i++){
            if(A[i]){
                firstOneCount++;
                if(firstOneCount == oneCount / 3){
                    break;
                }
            }
        }

        //since the first part must equal the last part
        //we count the number of zeros after the last one
        //and check if there are the same amount of zeros
        //after the first part
        int numLastZeros = A.size() - 1 - lastOne;
        int boolean = 1;
        for(int count = 0; count < numLastZeros; count++){
            if(A[i + 1 + count])
                boolean = 0;
        }
        if(boolean == 0)
            return {-1, -1};

        i += numLastZeros;

        //do for j the same thing we did for i
        int j = 0;
        int secondOneCount = 0;
        for(; j < A.size(); j++){
            if(A[j]){
                secondOneCount++;
                if(secondOneCount == oneCount / 3 * 2)
                    break;
            }
        }

        boolean = 1;
        for(int count = 0; count < numLastZeros; count++){
            if(A[j + 1 + count])
                boolean = 0;
        }
        if(boolean == 0)
            return {-1, -1};

        j += numLastZeros + 1;


        //check if three parts agree
        int first = i, second = j - 1, third = A.size() - 1;
        while((first >= 0) || (second >= i + 1) || (third >= j)){
            if(get(0, first) != get(i + 1, second) || (get(0, first) != get(j, third))){
                return {-1, -1};
            }
            first--;
            second--;
            third--;
        }

        return {i, j};

    }
};
