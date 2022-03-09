class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();

        //since, there is no 3rd element to compare
        if(n==2)
            return true;
        sort(begin(arr), end(arr));
        for(int i=0; i<n-2; i++)
        {
            //checking the difference between any 2 consecutive elements
            if(arr[i] - arr[i+1] != arr[i+1] - arr[i+2])
                return false;
        }
        return true;
    }
};
