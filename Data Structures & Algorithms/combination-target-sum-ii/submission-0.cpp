class Solution {
public:
    void helper(vector<vector<int>>& ans,
                vector<int>& current,
                int start,
                vector<int>& nums,
                int target) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicates at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Since nums is sorted
            if (nums[i] > target)
                break;

            current.push_back(nums[i]);

            // i + 1 because each number can be used only once
            helper(ans, current, i + 1, nums, target - nums[i]);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> current;

        helper(ans, current, 0, nums, target);

        return ans;
    }
};