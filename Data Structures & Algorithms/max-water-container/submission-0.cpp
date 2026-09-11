class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
		int i = 0, j = n-1;
		int maxi = INT_MIN;
		while(i<j){
			int area = (j-i) *(min(heights[i], heights[j]));
			maxi = max(maxi, area);
			if(heights[i]>heights[j])j--;
			else i++;
		}
		return maxi;
    }
};
