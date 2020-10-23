// Given a linked list, return the node where the cycle begins. If there is no cycle,
// return null. There is a cycle in a linked list if there is some node in the list that
// can be reached again by continuously following the next pointer.

// C++ code to detect the cycle and find the node where the cycle begins in the linked
// list It uses Floyd's cycle finding algorithm It contains an O(1) Space Complexity and
// O(n) [*][0] Time Complexity solution to detect cycle in a linked list and return the node
// where the cycle starts.
//
// [0]: https://medium.com/@nikeshshetty/floyd-cycle-detection-ef2642022578

// Definition for LinkedList node
struct node
{
	int val;
	node *next;
	node(int x) : val{x}, next{nullptr}
	{
	}
};

class Solution
{
  public:
	node *detectCycle(node *head)
	{
		node *slow, *fast;
		if (head == nullptr)
			return nullptr;
		slow = head;
		fast = head;
		while (slow && fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				break;
			}
		}
		bool isCycle = slow == fast;
		if (isCycle)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
		else
		{
			return nullptr;
		}
	}
};
