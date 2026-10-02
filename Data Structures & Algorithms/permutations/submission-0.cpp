class Solution {
public:

    void helper(vector<vector<int>>& ans,
                vector<int>& current,
                vector<bool>& used,
                vector<int>& nums) {

        // One complete permutation
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Try every number for this position
        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            // Choose
            current.push_back(nums[i]);
            used[i] = true;

            helper(ans, current, used, nums);

            // Backtrack
            used[i] = false;
            current.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        helper(ans, current, used, nums);

        return ans;
    }
};