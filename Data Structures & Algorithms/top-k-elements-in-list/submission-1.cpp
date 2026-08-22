class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //bucket sort approach
        vector<vector<int>>bucket(nums.size()+1);
        unordered_map<int, int>mpp;
        for(int x: nums){
            mpp[x]++;
        }
        for(auto i: mpp){
            bucket[i.second].push_back(i.first);
        }
        vector<int>ans;
        for(int i = nums.size(); i>=0; i--){
            if(!bucket[i].empty() && k!=0){
                for(int x: bucket[i]){
                    ans.push_back(x);
                    k--;
                }
            }

        }
        return ans;
    }
};
