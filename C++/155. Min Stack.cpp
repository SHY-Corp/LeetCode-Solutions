/*Problem statement:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

/*
Approach:
 We use a basic approach of storing the minimum element in another stack, and updating accordingly as we push and pop.
 */

class MinStack {
public:
    /** we use a basic extra stack approach for managing the min element in the stack */
    stack<int> original_stack;
    stack<int> min_stack;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if(original_stack.empty())
        {
            original_stack.push(x);
            min_stack.push(x);
            return;
        }
        if(x < min_stack.top())
        {
            original_stack.push(x);
            min_stack.push(x);
        }
        else
        {
            original_stack.push(x);
            int min_int = min_stack.top();
            min_stack.push(min_int);
        }
        
    }
    
    void pop() {
        original_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return original_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

