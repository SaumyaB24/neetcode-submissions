class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m) return false;
        vector<int> s1mpp(26, 0);
        vector<int> s2mpp(26, 0);
        for (int i = 0; i < n; i++) {
            s1mpp[s1[i] - 'a']++;
            s2mpp[s2[i] - 'a']++;
        }
        int match = 0;
        for (int i = 0; i < 26; i++) {
            if (s1mpp[i] == s2mpp[i]) {
                match++;
            }
        }
        int i = 0;
        int j = n - 1;
        while (j < m) {

            if (match == 26) {
                return true;
            }
            int left = s2[i] - 'a';

            if (s1mpp[left] == s2mpp[left]) {
                match--;
            }

            s2mpp[left]--;
            
            if (s1mpp[left] == s2mpp[left]) {
                match++;
            }

            i++;
            j++;
            if (j < m) {
                int right = s2[j] - 'a';

                if (s1mpp[right] == s2mpp[right]) {
                    match--;
                }
                s2mpp[right]++;
                if (s1mpp[right] == s2mpp[right]) {
                    match++;
                }
            }
        }

        return match == 26;
    }
};