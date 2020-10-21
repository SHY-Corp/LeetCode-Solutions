// Problem Link: https://leetcode.com/problems/range-sum-query-mutable/ 
/* 1. Given an integer array,we need to find the sum of elements in given range [i,j]      
   2. Array is modifiable(mutable) by update(int i,int val) function that replaces element at index i with value val 
*/
/*
  Solution Idea:
  A segment tree is a flexible data structure that allows us to find range queries in O(logn) time.
  -----------------------------------------------------------------------------------
  VARIABLES DESCRIPTION:
  tree[]=segment tree array
  index=no of vertices starting with root at 0
  qs=start index of segment
  qe=end index of segment 
  s=start index of tree
  e= end index of tree
  left child at index= (2*index)
  right child at index =(2*index+1)
  ------------------------------------------------------------------------------------
 we start with the segment nums[0…n−1], split the current segment in half (if it has not yet become a segment containing a single element), and then calling the same procedure for both halves. For each such segment we store the sum of the numbers on it.
  
*/

class NumArray{

int tree[];
int n;
int index=1;

public NumArray(int[] nums) {
    this.n = nums.length;
    //The number of vertices in the worst case can be estimated by the sum 1+2+4+⋯+2⌈log2n⌉=2⌈log2n⌉+1<4n.
    this.tree = new int[4*n+2];
    build(tree,nums,1,0,n-1);
}

 public static void build(int tree[], int arr[], int index, int s, int e) {   
    // Building the Segment Tree
    if (s > e) {
        return;
    }
    if (s == e) {
        tree[index] = arr[s];
        return;
    }
    int mid = s+(e-s)/2;
    build(tree,arr,2*index,s,mid);
    build(tree,arr,2*index+1,mid+1,e);
    tree[index] = tree[2*index]+tree[2*index+1];
}

 public static int query(int tree[], int index, int s, int e, int qs, int qe) {
    if (qe < s || e < qs)
        return 0; // no overlapping 
    if(s==e)
    return tree[index];
    int mid = (s+e)/2; // Partial Overlapping
    int l= query(tree,2*index,s,mid,qs,qe);//left child
    int r= query(tree,2*index+1,mid+1,e,qs,qe);//right child
    return l+r;
}
//For update in Array
public static void upd(int tree[], int index, int s, int e,int i, int value) {
   if (i < s || i > e) return; // Out of range
   if (s == e) {
       tree[index] = value; // Index position found
       return;
   }
   int mid = (s+e)/2;    // for partial found position
   upd(tree,2*index,s,mid,i,value);
   upd(tree,2*index+1,mid+1,e,i,value);
   tree[index] = tree[2*index]+tree[2*index+1];
}

public void update(int i, int val) {
   upd(tree,index,0,n-1,i,val);
}


public int sumRange(int i, int j) {
   return query(tree,index,0,n-1,i,j);

}}