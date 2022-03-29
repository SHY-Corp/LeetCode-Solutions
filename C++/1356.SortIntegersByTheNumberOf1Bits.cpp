class Solution {
public:
    //counting the no. of 1's in the binary representation of each integer in the array
    static int countBits(int n)
    {
        int count=0;
        while(n>0)
        {
            //returns the no. of 1's in binary form
            n = n&(n-1);
            count++;
        }
        return count;
    }
    //checking the no. of 1-bits in the successive numbers of the array for sorting them
    static bool cmp(int a, int b)
    {
        if(countBits(a)==countBits(b))
        {
            return a<b;
        }

        if(countBits(a)>countBits(b))
        {
            return false;
        }
        return true;
    }
    vector<int> sortByBits(vector<int>& arr) {
        //sorting the array on the basis of frequency of no. of 1's in ascending order
        sort(begin(arr), end(arr),cmp);
        return arr;
    }
};
