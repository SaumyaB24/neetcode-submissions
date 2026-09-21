class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;  // min-heap of size k
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int x : nums) {
            add(x);
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();  // remove smallest, keep the k largest
        return pq.top();              // smallest of the k largest = kth largest
    }
};