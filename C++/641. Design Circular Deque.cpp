// 641 Design Circular Deque
/*Design your implementation of the circular double-ended queue (deque).*/
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity_ = k;
        data_.reserve(k);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())
            return false;
        
        ++count_;
        front_ = (front_-1+capacity_)%capacity_;
        data_[front_] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())
            return false;
        
        ++count_;
        int rear = (front_+count_-1)%capacity_;
        data_[rear] = value;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())
            return false;
        
        --count_;
        front_ = (front_+1)%capacity_;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())
            return false;
        
        --count_;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty())
            return -1;
        
        return data_[front_];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
         if(isEmpty())
            return -1;
        
       return data_[(front_+count_-1)%capacity_];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count_ == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count_ == capacity_;
    }
    private:
    int count_ = 0;
    int front_ = 0;
    int capacity_ = 0;
    vector<int> data_;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */