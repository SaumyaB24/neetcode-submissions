class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        map<char, int> mpp;
        for (char task : tasks) {
            mpp[task]++;
        }
        for (auto it : mpp) {
            pq.push(it.second);
        }
        int time = 0;
        while (!pq.empty() || !q.empty()) {
            if (pq.empty()) {
                time = q.front().second;
            }
            while (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }
            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                freq--;
                if (freq > 0) {
                    q.push({freq, time + n + 1});
                }
            }

            time++;
        }
        return time;
    }
};