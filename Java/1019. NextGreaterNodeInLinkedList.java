/*
We are given a linked list with head as the first node.  Let's number the nodes in the list: node_1, node_2, node_3, ... etc.
Each node may have a next larger value: for node_i, next_larger(node_i) is the node_j.val such that j > i, node_j.val > node_i.val, and j is the smallest possible choice.  
If such a j does not exist, the next larger value is 0.
Return an array of integers answer, where answer[i] = next_larger(node_{i+1}).

Approach:-
1.All the Elements in the Linked List are moved into an ArrayList.
2.An Array is created for result and a Stack is Created which maintains index of elements.
3.We traverse the list by index and push the index of element directly in stack if the current top of stack is greater 
than the current list element or stack is empty.
4.Else if the stack top is smaller than the current element,then keep popping elements until greater
element is found or else stack is empty.Current element becomes the result of the popped index from the stack.
5.Set array[popped_item]=Current list element.Push index of current element in stack.
6.Finally the remaining index elements in stack have no greater value.Set these indexes as 0 in result array.(Java does automatically during intialization).
*/ 


class Solution {
    public int[] nextLargerNodes(ListNode head) {
     
        int length=0;
        List<Integer> l =new ArrayList<>();
        
        while(head!=null){
            l.add(head.val);
            head=head.next;
        }
        int a[]=new int[l.size()];
        
        
        Stack<Integer> s =new Stack<>();
        
        for(int i=0;i<l.size();i++) {
            
    
                while(!s.isEmpty() && l.get(s.peek())<l.get(i) ) {
                    a[s.pop()]=l.get(i);
                }
                s.push(i);
            }
        return a;
        
    }
}
