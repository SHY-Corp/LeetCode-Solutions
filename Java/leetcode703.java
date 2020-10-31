PriorityQueue<Integer> pq = new PriorityQueue<>();
    int size;

    public KthLargest(int k, int[] nums) {
        size = k;
        for (int ele : nums) {
        pq.add(ele);

        if (pq.size() > k) {
        pq.remove();
        }
    }
    }

    public int add(int val) {
        pq.add(val);

        if (pq.size() > size) {
            pq.remove();
        }
        return pq.peek();
    }