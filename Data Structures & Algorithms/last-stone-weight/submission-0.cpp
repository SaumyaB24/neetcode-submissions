class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end()); // max-heap

        while (pq.size() >= 2) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            int diff = abs(x - y);
            if (diff > 0) pq.push(diff);
        }

        return pq.empty() ? 0 : pq.top();
    }
};