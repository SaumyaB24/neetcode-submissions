class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),1);
        //prefix
        int pre = 1;
        for(int i = 0; i<nums.size()-1; i++){
            ans[i+1] = pre*nums[i];
            pre *= nums[i];
        }
        //postfix
        int post = 1;
        for(int i = nums.size()-1; i>=0; i--){
            ans[i] *= post;
            post *= nums[i];
        }//time - O(n)
        return ans;//space - O(n) - to store answer
    }
};
