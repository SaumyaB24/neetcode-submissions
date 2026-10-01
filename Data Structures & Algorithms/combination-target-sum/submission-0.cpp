class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& current,
                int i, vector<int>& nums, int n,
                int& k, int currSum) {

        // Target reached
        if (currSum == k) {
            ans.push_back(current);
            return;
        }

        // No more elements
        if (i == n) {
            return;
        }

        // Take nums[i]
        // We stay at i because we can reuse the same number
        if (currSum + nums[i] <= k) {
            current.push_back(nums[i]);

            helper(ans, current, i, nums, n,
                   k, currSum + nums[i]);

            current.pop_back();
        }

        // Not take nums[i]
        helper(ans, current, i + 1, nums, n,
               k, currSum);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        helper(ans, current, 0, nums, nums.size(),
               target, 0);

        return ans;
    }
};