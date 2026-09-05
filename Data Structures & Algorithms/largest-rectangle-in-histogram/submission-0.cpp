class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>>st;//{index, height}
        int maxArea = 0;
        for(int i = 0; i<n; i++){
            int start = i;
            while(!st.empty() && st.top().second>heights[i]){
                maxArea = max(maxArea, st.top().second*(i-st.top().first));
                start = st.top().first;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while(!st.empty()){
            auto [ind, h] = st.top();
            maxArea = max(maxArea, h*(n-ind));
            st.pop();
        }
        return maxArea;
    }
};
