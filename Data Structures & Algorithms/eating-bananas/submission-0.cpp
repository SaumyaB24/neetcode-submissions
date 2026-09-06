class Solution {
public:
    int maxVal(vector<int>& piles){
        int maxi = 0;
        for(int i = 0; i<piles.size(); i++){
            maxi = max(piles[i], maxi);
        }
        return maxi;
    }
    int calculateHours(vector<int>& piles, int k){
        int totalH = 0;
        for(int i = 0; i<piles.size(); i++){
            totalH += ceil((double)piles[i] / k);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxVal(piles);
        while(low<=high){
            int mid = low + (high-low)/2;
            int totalH = calculateHours(piles, mid);
            if(totalH<=h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
