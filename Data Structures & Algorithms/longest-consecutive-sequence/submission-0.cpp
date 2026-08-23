class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int,int>mpp;
        for(int x:nums){
            mpp[x]=1;
        }
        int maxlen = 1;
        for(auto it:mpp){
            int prev = it.first;
            if(mpp.find(prev-1) == mpp.end()){//to check if the beginning of a sequence
                int len = 1;
                int next = prev + 1;

                while (mpp.find(next) != mpp.end()) {
                    len++;
                    next++;
                }
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};