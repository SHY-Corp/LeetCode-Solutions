/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
 
Given tree t:

   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
*/

class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s == null){
            return false;
        }else if(isSame(s,t)){
            return true;
        }else{
            boolean checkL = isSubtree(s.left, t);
            if(checkL){
                return true;
            }
            boolean checkR = isSubtree(s.right, t);
            if(checkR){
                return true;
            }
            
            return false;
        }
    }
    
    public boolean isSame(TreeNode s, TreeNode t){
        if(s == null || t == null){
            return (s == null) && (t == null);
        }else if(s.val == t.val){
            return isSame(s.left, t.left) && isSame(s.right,t.right);
        }else{
            return false;
        }
    }
}
