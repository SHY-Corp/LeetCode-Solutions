/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    /*    Node* copy;
        unordered_map<Node*, Node*> mp;

        //creating copy of copy node pointing to the head of given linked list
        while(copy!=NULL)
        {
            mp[copy] = new Node(copy->val);
            copy=copy->next;
        }

        //for traversing again
        copy = head;

        //linking the next and random pointers of copied nodes
        while(copy!=NULL)
        {
            mp[copy]->next = mp[copy->next];
            mp[copy]->random = mp[copy->random];
            copy = copy->next;
        }
        return mp[head];

  //TC=O(n); SC=O(n), hashmap is increasing the space complexity!

        */

        //better approach, without using the hashmaps! We are intertwining the nodes.
        Node* curr = head;

        //the linkedlist is now including its arbitrary values, i.e. 7->7', thus, there will be copies
        //within the linked list
        while(curr!=NULL)
        {
            // intertwining the new nodes to the current node
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }

        curr = head;

        //fixing the random pointer in this pass
        while(curr!=NULL)
        {
            if(curr->random!=NULL)
            {
                curr->next->random = curr->random->next;
            }
            curr=curr->next->next;
        }

        //creating a dummy node which will further point to the new intertwined nodes
        Node* dummy = new Node(-1);
        Node* curr1 = head;   //original nodes
        Node* curr2 = dummy;  //dummy

        //breaking the intertwined nodes and fixing the next pointers
        while(curr1!=NULL)
        {
            //breaking the next pointer of original node with dummy node
            curr2->next = curr1->next;
            curr2=curr2->next;
            //original node's next pointer will skip one node as there is 1 dummy node between 2 original nodes
            curr1->next = curr1->next->next;
            curr1 = curr1->next;
        }

        return dummy->next;
    }
};

//TC=O(n), SC=O(1)

/*
    https://www.youtube.com/watch?v=Zo_u4rzfgIk

*/

