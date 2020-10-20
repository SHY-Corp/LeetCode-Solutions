/**
You have an infinite number of stacks arranged in a row and numbered (left to right) from 0, each of the stacks has the same maximum capacity.

Implement the DinnerPlates class:

- DinnerPlates(int capacity) Initializes the object with the maximum capacity of the stacks.
- void push(int val) Pushes the given positive integer val into the leftmost stack with size less than capacity.
- int pop() Returns the value at the top of the rightmost non-empty stack and removes it from that stack, and returns -1 if all stacks are empty.
- int popAtStack(int index) Returns the value at the top of the stack with the given index and removes it from that stack, and returns -1 if the stack with that given index is empty.


Constraints:

- 1 <= capacity <= 20000
- 1 <= val <= 20000
- 0 <= index <= 100000
- At most 200000 calls will be made to push, pop, and popAtStack

 * ref: https://leetcode.com/problems/dinner-plate-stacks/
 */

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
 
class DinnerPlates {
private: 
    int capacity;
    vector<vector<int>> plates;
    int i;
public:
    DinnerPlates(int capacity):capacity{capacity} { 
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        i = 0;
    }
    
    void push(int val) {
        if (plates.empty()){
            vector<int> temp;
            temp.push_back(val);
            plates.push_back(temp);
        }else{
         
            //int i = 0;
            while (i < plates.size() && plates[i].size() == capacity){
                i++;  
            }
            // create new item
            vector<int> temp;
            temp.push_back(val);
            
            //all stacks full, create new stack
            if (i == plates.size()){
                plates.push_back(temp);
            }else{
                //use stack i
                plates[i].push_back(val); //add to stack i
            }
        }  
    }
    
    int pop() {
        i = 0;
        if (plates.empty() || plates.back().empty()){
            return -1;
        }else{
            int ret = plates.back().back();
            plates.back().pop_back();
            if(!plates.empty() && plates.back().empty()){
                plates.pop_back();
            }
            return ret;
        }
    }
    
    int popAtStack(int index) {
        i = 0;
        if (plates.empty() || index >= plates.size() || plates[index].empty()){
            return -1;
        }else{
            int ret = plates[index].back();
            plates[index].pop_back();
            return ret;
        }
    }
};
