class KthLargest {
public:
    //creating a priority queue(min-heap) to find the largest element in a stream
    priority_queue<int, vector<int>, greater<int>> minqheap;
    int len;
    KthLargest(int k, vector<int>& nums) {
        //maintaining a global variable and storing the value of k in it
        len = k;

        //iterating over the data stream array; pushing the values in min heap; and if the size of the queue
        //exceeds k, popping that value.
        for(int i=0; i<nums.size(); i++)
        {
            minqheap.push(nums[i]);
            if(minqheap.size() > k)
            {
                minqheap.pop();
            }
        }
    }

    int add(int val) {
        //pushing the value in min-heap
        minqheap.push(val);

        //if the min-heap size is more than len, popping the heap
        if(minqheap.size() > len)
        {
            minqheap.pop();
        }
        //the current top of the heap will give the kth largest element
        return minqheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/*
   TC: O(nlog(n) + mlog(k)), where n = size of array and m = no. of calls to add() function
   SC: O(n), heap will originally be of size n
*/
