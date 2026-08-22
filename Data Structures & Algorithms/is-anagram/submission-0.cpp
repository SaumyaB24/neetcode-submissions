class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n != m)return false;
        vector<int>freq(26,0);//space - O(1)
        for(int i = 0; i<n; i++){//time - O(n)
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(int i = 0; i<26; i++){
            if(freq[i]!=0)return false;
        }
        return true;
    }
};
