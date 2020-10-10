/**
 * The challenge no.215 asks for the kth largest element of an array to be returned.
 * 
 * To solve this problem, the array has to be sorted and then the Kth element from the top will be returned.
 * 
 * To save some processing time, the array only gets sorted for K elements which is slightly faster than sorting all elements.
 */
//used a priority queue to find the solution
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int ele: nums)
        {
            pq.add(ele);
            if(pq.size()>k)
                pq.remove();
        }
        
        return pq.peek();
    }

   
}
