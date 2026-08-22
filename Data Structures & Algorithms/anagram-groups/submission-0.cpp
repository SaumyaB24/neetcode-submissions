class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>>ans;
        map<vector<int>,vector<string>>mpp; //unordered_map needs   its key to be hashable. C++ does not provide a default hash function for vector<int>, that's why using map
        for(int i = 0; i<n ; i++){
            vector<int>freq(26,0);
            string s = strs[i];
            for(int i = 0; i<s.length(); i++){
                freq[s[i] - 'a']++;
            }
            mpp[freq].push_back(s);
        }
        for (auto x : mpp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};