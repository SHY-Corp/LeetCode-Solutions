
//Program to reverse a linked list from position m to n. Do it in one-pass. Note: 1 ≤ m ≤ n ≤ length of list.
//language c++.


class List{
   
   public:
      int val;
      List *next;
   
      List(int data){
         val = data;
         next = NULL;
      }
   
   };
   
   
   
   List *make_list(vector<int> v){
      List *head = new List(v[0]);
      for(int i = 1; i<v.size(); i++){
         List *ptr = head;
         while(ptr->next != NULL){
            ptr = ptr->next;
         }
         ptr->next = new List(v[i]);
      }
      return head;
   }
   
   
   void print_list(List *head){
      List *ptr = head;
      cout << "[";
      while(ptr){
         cout << ptr->val << ", ";
         ptr = ptr->next;
      }
      cout << "]" << endl;
 }


 class Solution {
   
   public:
   
      List* successor = NULL;
   
      List* reverseN(List* head, int n ){
         if(n == 1){
            successor = head->next;
            return head;
         }
         List* last = reverseN(head->next, n - 1);
         head->next->next = head;
         head->next = successor;
         return last;
      }
   
   
      List* reverseBetween(List* head, int m, int n) {
      if(m == 1){
            return reverseN(head, n);
      }
      head->next = reverseBetween(head->next, m - 1, n - 1);
            return head;
   }
 };