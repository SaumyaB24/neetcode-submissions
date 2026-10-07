class Solution {
public:

    bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void helper(int i, string& s,
                vector<vector<string>>& ans,
                vector<string>& curr) {

        // Entire string has been partitioned
        if(i == s.length()) {
            ans.push_back(curr);
            return;
        }

        // Try every possible ending position
        for(int j = i; j < s.length(); j++) {

            // Take s[i...j] only if it is palindrome
            if(isPalindrome(s, i, j)) {

                curr.push_back(s.substr(i, j - i + 1));

                helper(j + 1, s, ans, curr);

                // Backtrack
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> curr;

        helper(0, s, ans, curr);

        return ans;
    }
};