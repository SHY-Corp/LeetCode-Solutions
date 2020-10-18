/*
PROBLEM - 1310. XOR Queries of a Subarray

DESCRIPTION -

Given the array arr of positive integers and the array queries where
queries[i] = [Li, Ri], for each query i compute the XOR of elements from
Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ).
Return an array containing the result for the given queries.

CONSTRAINTS-

1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 10^9
1 <= queries.length <= 3 * 10^4
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] < arr.length

APPROACH-

-- In this solution the property of XORs where a^(a^b)=b is exploited.
-- First populate a prefix XOR array where array[i] is the running XOR of all
   the elements from 0 to i.
-- Then all the queries are answered in constant time using the above mentioned
   property i.e.
   XOR(l,r) = prefix(r) ^ prefix(l) = (XOR(0,l) ^ XOR(l^r)) ^ XOR(0,l)

TIME COMPLEXITY-

TC of solution O(n) where n is max(arr.length,queries.length)

*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>pref, ans; // pref is the XOR prefix, ans is answer vector
        int pre = 0;         // variable for maintaining continuous XOR
        for (auto& num : arr) // populating the pref array
        {
            pref.push_back(num ^ pre);
            pre ^= num;
        }
        for (auto& q : queries) // answering the input queries
        {
            if (q[0] == 0) ans.push_back(pref[q[1]]);
            else ans.push_back(pref[q[1]]^pref[q[0] - 1]);
        }
        return ans;
    }
};