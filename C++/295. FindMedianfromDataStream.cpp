class MedianFinder {
    priority_queue<int> left; // maxheap
    priority_queue<int, vector<int>, greater<int>> right; // minheap
public:
    /** initialize your data structure here. */
    MedianFinder() {
        // do nothing.
    }
    
    void addNum(int num) {
        if(left.size() == 0 || num < left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }
        
        if(right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        } else if (left.size() - 1 > right.size()) {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        int combinedSize = left.size() + right.size();
        if(combinedSize == 0) {
            return 0;
        } 
        
        if(combinedSize % 2 == 0) {
            return ((double) left.top() + (double) right.top()) / (double) 2; 
         } else {
            return left.top();
        }
    }
};