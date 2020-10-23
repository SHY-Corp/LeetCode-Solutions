/*

Problem : You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window

Approach : We scan the array from 0 to n-1, keep favourable elements in the deque. The algorithm is amortized O(n) as each element is put and polled once.
           At each i, we keep favourable elements, which are potentially max number in window [i-(k-1),i] or any subsequent window. This means if an element in the deque and it is out of i-(k-1), we discard them. We just need to pop from the head, as we are using a deque and elements are ordered as the sequence in the array
		   Now only those elements within [i-(k-1),i] are in the deque. We then discard elements smaller than a[i] from the tail. This is because if a[x] <a[i] and x<i, then a[x] has no chance to be the "max" in [i-(k-1),i], or any other subsequent window: a[i] would always be a better candidate.
		   As a result elements in the deque are ordered in both sequence in array and their value. At each step the head of the deque is the max element in [i-(k-1),i]

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> v;
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
        }
        for(int i = k; i < n; i++) {
            v.push_back(dq.front());
            if(dq.front() == nums[i - k]) dq.pop_front();
            while(!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
        }
        v.push_back(dq.front());
        return v;
    }
};
