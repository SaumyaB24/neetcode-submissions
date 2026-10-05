class Solution {
public:
    void helper(int index, vector<int>& nums, vector<int>& curr,
                vector<vector<int>>& ans, int n) {

        if(index >= n) {
            ans.push_back(curr);
            return;
        }
        // Take nums[index]
        curr.push_back(nums[index]);
        helper(index + 1, nums, curr, ans, n);
        curr.pop_back();
        // Don't take nums[index]
        int i = index + 1;

        while(i < n && nums[index] == nums[i]) {
            i++;
        }
        helper(i, nums, curr, ans, n);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        int n = nums.size();
        helper(0, nums, curr, ans, n);
        return ans;
    }
};