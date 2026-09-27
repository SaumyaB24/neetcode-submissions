class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        vector<int> freqS(128, 0);
        vector<int> freqT(128, 0);
        int n = s.length();
        int m = t.length();
        if (m > n) return ans;
        int have = 0;
        int need = 0;
        for (int i = 0; i < m; i++) {
            freqT[t[i]]++;
            if (freqT[t[i]] == 1) {
                need++;
            }
        }
        int l = 0;
        int r = 0;
        int minLen = INT_MAX;
        int start = 0;
        while (r < n) {
            freqS[s[r]]++;
            if (freqT[s[r]] > 0 &&
                freqS[s[r]] == freqT[s[r]]) {
                have++;
            }
            while (have == need) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                freqS[s[l]]--;
                if (freqT[s[l]] > 0 &&
                    freqS[s[l]] < freqT[s[l]]) {
                    have--;
                }

                l++;
            }

            r++;
        }
        if (minLen == INT_MAX) {
            return "";
        }
        return s.substr(start, minLen);
    }
};