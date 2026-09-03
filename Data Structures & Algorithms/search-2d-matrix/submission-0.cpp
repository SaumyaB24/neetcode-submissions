class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
		int cols = matrix[0].size();
		int start = 0, end = (rows-1)*cols + (cols-1);
		while(start <= end){
			int mid = end + (start-end)/2;
			int i = mid/cols;
			int j = mid%cols;
			if(matrix[i][j]<target)start = mid+1;
			else if(matrix[i][j] == target)return true;
			else end = mid-1;
		}
		return false;
    }
};