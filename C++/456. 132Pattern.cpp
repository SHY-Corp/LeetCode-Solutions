// Title 132 Pattern
// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
// Return true if there is a 132 pattern in nums, otherwise, return false.

// Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?
// we have given O(nlogn)solution
class Solution {
public:
    bool find132pattern(vector<int>& a) {
        int n=a.size();if(a.size()<3)return 0;
        vector<int>p(n,a[0]);
        for(int i=1;i<n;i++){
            p[i]=min(p[i-1],a[i]);
        }
        priority_queue<int>q;q.push(a[n-1]);
        for(int i=n-2;i!=0;i--){
            if(q.top()>p[i-1] and a[i]>q.top() and p[i-1]<a[i])return 1;
            q.push(a[i]);
        }
        return 0;
    }
};