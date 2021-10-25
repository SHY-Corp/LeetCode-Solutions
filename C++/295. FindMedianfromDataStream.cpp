/*
    We maintain 2 heaps with equal or almost equal sizes. meaning the size between one heap
    from another will have a difference of at most 1 item. We call them left heap and right heap
    so that the middle will always be the median. Then we add the items accordingly depending
    on the top item of the left numheap. Keep adding them and the top of the left heap will contain
    the median in the case of an odd numbered size, and both left and right heap top will be the median
    when there is an even numbered size.
*/

class MedianFinder {
    priority_queue<int> left;                              // maxheap
    priority_queue<int, vector<int>, greater<int>> right;  // minheap
   public:
    /** initialize your data structure here. */
    MedianFinder() {
        // do nothing.
    }

    void addNum(int num) {
        if (left.size() == 0 || num < left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        } else if (left.size() - 1 > right.size()) {
            right.push(left.top());
            left.pop();
        }
    }

    double findMedian() {
        int combinedSize = left.size() + right.size();
        if (combinedSize == 0) {
            return 0;
        }

        if (combinedSize % 2 == 0) {
            return ((double)left.top() + (double)right.top()) / (double)2;
        } else {
            return left.top();
        }
    }
};