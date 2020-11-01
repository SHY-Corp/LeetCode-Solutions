// 341. Flatten Nested List Iterator
/*
Problem Statement 

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Examples 1:
Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,1,2,1,1].

Examples 2:
Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,4,6].


 Approach
 The question offered interfaces to help us. We can use vector to store the  integer elements in nestedList. We store elements in vector recursively. We loop on the nestedList list and for current list we get integer elemnts stored in it, then we call same function but using next list
 In next function we return value in current index in the vector and increment the index, in hasNext function we check if we reached  full vector size using index or not;
*/








/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> flatten;
    int current = 0;
    
    void addElementFromList(vector<NestedInteger>& nestedList) {
        for(auto element : nestedList) {
            if(element.isInteger())
                flatten.push_back(element.getInteger());
            else {
                addElementFromList(element.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        addElementFromList(nestedList);
    }
    
    int next() {
        return flatten.at(current++);
    }
    
    bool hasNext() {
        return current != flatten.size();
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */