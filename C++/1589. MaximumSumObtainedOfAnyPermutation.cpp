/*
   Problem Statement :
        #1589.
            We have an array of integers, nums, and an array of requests where requests[i] = [starti, endi].
            The ith request asks for the sum of nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi].
            Both starti and endi are 0-indexed.
            Return the maximum total sum of all requests among all permutations of nums.
            Since the answer may be too large, return it modulo 10^9 + 7.

    Constraints:
            n == nums.length
            1 <= n <= 10^5
            0 <= nums[i] <= 10^5
            1 <= requests.length <= 10^5
            requests[i].length == 2
            0 <= starti <= endi < n

    Approach:
            The constraints allow us the use O(nlogn) approach; We want the maximum total sum for all the permutations of
            nums. The intuition favors the case where maximum frequency element is multiplied by the maximum element and
            henceforth. If we find out the frequency of all the indexes and then multiply the maximum frequency with the
            maximum element in the array and second highest frequency index with the second highest element and so on and
            so forth , we are good to go. The frequency is calculated by prefix sum approach (O(n)) and the inherent sort
            takes (O(nlogn)) in the worst case, so overall time complexity => max{O(n) , O(nlogn)} = O(nlogn)

*/

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int size = nums.size();
        int freq[size];
        memset(freq,0,sizeof(freq));
        for(auto &x: requests){
            freq[x[0]] += 1;
            if(x[1]+1 < size)
                 freq[x[1]+1] -= 1;
        }
        for(int i=1;i<size;i++){
            freq[i] += freq[i-1];
        }
        long long sum=0;
        sort(freq, freq+size);
        sort(nums.begin(), nums.end());
        for(int i=0;i<size;i++){
                sum += (((long long)freq[i]*nums[i]));
        }
        return sum % 1000000007;
    }
};
