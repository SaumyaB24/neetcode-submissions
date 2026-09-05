class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>arr(speed.size());
        stack<float>st;
        for(int i = 0; i<speed.size(); i++){
            arr[i] = {position[i], speed[i]};
        }
        //sort in descending order on the basis of position
        sort(arr.begin(), arr.end(), greater<pair<int,int>>());
        for(int i = 0; i<arr.size(); i++){
            float time = (float)(target - arr[i].first) / arr[i].second;
            if(st.empty() || (!st.empty() && st.top()<time)){
                st.push(time);
            }
        }
        return st.size();
    }
};
