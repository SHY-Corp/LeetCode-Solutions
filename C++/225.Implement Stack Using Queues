/* Implement Stack Using Queues.cpp
   So push time is O(1), while push and top takesO(n) time
   description is explained in between
 */ 



Queue<Integer> queue
ALGORITHM constructor
    this.queue = a new Queue object storing Integer
ALGORITHM push(x)
    queue.push(x)
ALGORITHM pop()
    // if we pop directly from queue, the element won't be on top of our "stack", so need a way to get the latest added element
    tmp = a new Queue object storing Integer
    // push everything in queue to tmp except the last one
    while (queue.size() > 1) {
        tmp.push(queue.pop())
    }
    // pop the remaining element out from the queue
    stack_pop = queue.pop()
    // simply switch reference
    this.queue = tmp
    return stack_pop
ALGORITHM top()
    // very much similar to pop()
    tmp = a new Queue object storing Integer
    while (queue.size() > 1) {
        tmp.push(queue.pop())
    }
    stack_top = queue.top()
    tmp.push(queue.pop())
    this.queue = tmp
    return stack_top
ALGORITHM empty()
    return queue.empty()
