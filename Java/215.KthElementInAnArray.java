/**
 * The challenge no.215 asks for the kth largest element of an array to be returned.
 * 
 * To solve this problem, the array has to be sorted and then the Kth element from the top will be returned.
 * 
 * To save some processing time, the array only gets sorted for K elements which is slightly faster than sorting all elements.
 */
//Solving this question using a min heap of size K.
//We start adding elements in the priority queue and when the size exceeds K we pop the topmost element(minimum element).
//This way when we are done inserting all the array elements in the priority queue and simultaneously popping according to priority,
//At the end, we are left with a priority queue of size K and the topmost element is the Kth largest.
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
