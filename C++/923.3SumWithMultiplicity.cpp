class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> m;
        int mod = 1e9 + 7;
        long res = 0;

        //storing the count of each element in an unordered map
        for(auto a: arr)
        {
            m[a]++;
        }
        for(auto it: m)
        {
            for(auto x: m)
            {
                //maintaining 3 variables, 2 of which already exist in the input array and checking if the
                //3rd variable(obtainined after subtracting the sum of 1st 2 from the target) exists
                int i = it.first, j = x.first, k = target - i - j;
                if (!m.count(k)) continue;

                //if all variables are equal, dividing the combinations with 3!(=6)
                if (i == j && j == k)
                    res += m[i] * (m[i] - 1) * (m[i] - 2) / 6;

                //if 2 variables are equal, dividing the combination with 2!(=2)
                else if (i == j && j != k)
                    res += m[i] * (m[i] - 1) / 2 * m[k];

                //if all variables are different, we only care about the total combinations
                else if (i < j && j < k)
                    res += m[i] * m[j] * m[k];
            }
        }
        return res%mod;
    }
};

/*
Time Complexity : O(n*n), where n = lenghth of input array
Space Complexity : O(1)
*/
