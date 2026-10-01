class Solution {
public:
    void helper(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>curr, int n){
        if(i == n){
            ans.push_back(curr);
            return;
        }
        //take
        curr.push_back(nums[i]);
        helper(i+1, nums, ans, curr, n);
        //not take
        curr.pop_back();
        helper(i+1, nums, ans, curr, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(0, nums, ans, curr, nums.size());
        return ans;
    }
};
