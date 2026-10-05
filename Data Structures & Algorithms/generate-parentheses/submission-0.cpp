class Solution {
public:
    void helper(int open, int close, vector<string>& ans,
                string& curr, int n) {

        if(open >= n && close >= n) {
            ans.push_back(curr);
            return;
        }

        // Open bracket
        if(open < n) {
            curr.push_back('(');
            helper(open + 1, close, ans, curr, n);
            curr.pop_back();
        }

        // Close bracket
        if(close < open) {
            curr.push_back(')');
            helper(open, close + 1, ans, curr, n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        helper(0, 0, ans, curr, n);
        return ans;
    }
};