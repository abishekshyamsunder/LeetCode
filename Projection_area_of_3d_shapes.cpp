class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        //z(missing)-number of cubes placed - 2
        //y(missing)-max in each row - 3
        //x(missing)-max in each column -3
        int sum_z = 0;
        int sum_y = 0;
        int sum_x = 0;
        int max_row,max_col;
        for(int i=0;i<grid.size();i++)
        {
            max_row = INT_MIN;
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]>0)
                    sum_z++;
                max_row = max(max_row,grid[i][j]);
            }
            sum_y = sum_y + max_row;
        }
        
        for(int i=0;i<grid.size();i++)
        {
            max_col = INT_MIN;
            for(int j=0;j<grid.size();j++)
            {
                max_col = max(max_col,grid[j][i]);
            }
            sum_x = sum_x + max_col;
        }
        return sum_x+sum_y+sum_z;
    }
};
