class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix[0].size(); //number of columns
        int n = matrix.size(); //number of rows
        
        int j = -1;
        int start = 0;
        int end = n-1;
        
        while(start <= end)
        {
            j = (start + end)/2;
            if(matrix[j][m-1] >= target && j == 0 )
                break;
            else if(matrix[j][m-1] >= target && matrix[j-1][m-1] < target )
                break;
            else if(matrix[j][m-1] >= target)
                end = j - 1;
            else if(matrix[j][m-1] < target)
                start = j + 1;
        }
        cout<<j;
        start = 0;
        end = m-1;
        int i = -1;
         while(start <= end)
        {
            i = (start + end)/2;
            if(matrix[j][i] == target)
                return true;
            else if(matrix[j][i] < target)
                start = i + 1;
             else if(matrix[j][i] > target)
                 end = i - 1;
        }
        
        return false;
        
    }
};
