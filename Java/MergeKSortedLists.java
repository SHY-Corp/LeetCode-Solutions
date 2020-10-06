/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Time: O(N * k * log k)
Space: O(k)
*/

class NodeComparator implements Comparator<ListNode>{
	public int compare(ListNode a, ListNode b){
		if(a.val > b.val) return 1;
		else return -1;
	}
}

class Solution {
	public ListNode mergeKLists(ListNode[] lists) {
		if(lists.length == 0) return null;

		PriorityQueue<ListNode> heap = new PriorityQueue<>(lists.length, new NodeComparator());

		for(int i=0; i<lists.length; i++){
			if(lists[i] != null) heap.add(lists[i]);
		}

		ListNode res = new ListNode();
		ListNode curr = res;

		while(heap.size() != 0){
			ListNode buffer = heap.poll();

			curr.next = new ListNode(buffer.val);
			curr = curr.next;

			if(buffer.next != null) heap.add(buffer.next);
		}
		return res.next;
	}
}