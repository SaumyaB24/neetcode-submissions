class Solution {
public:

    int cal(int x, int y) {
        return x * x + y * y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int, pair<int, int>>
        > pq;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = cal(x, y);
            pq.push({dist, {x, y}});

            if (pq.size() > k) {
                pq.pop();  
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            ans.push_back({it.second.first, it.second.second});
        }
        return ans;
    }
};