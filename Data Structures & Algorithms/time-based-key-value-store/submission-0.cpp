class TimeMap {
    map<string, vector<pair<string,int>>> mpp; 
public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>>& temp = mpp[key];
        int low = 0, high = temp.size()-1;
        string ans;

        while(low<=high){
            int mid = low+(high-low)/2;

            if(temp[mid].second<=timestamp){ 
                ans = temp[mid].first;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        return ans;
    }
};