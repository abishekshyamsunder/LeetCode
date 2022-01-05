vector<vector<char>> ggrid;
vector<vector<int>> color;
int gsize_row;
int gsize_col;
void bfs_visit(int i, int j)
{
    // noi++;
    color[i][j] = 1;
    if(i!= 0 && ggrid[i-1][j] == '1' && color[i-1][j]==0)
        bfs_visit(i-1,j);
    if(i!= gsize_row-1 && ggrid[i+1][j] == '1' && color[i+1][j]==0)
        bfs_visit(i+1,j);
    if(j!= 0 && ggrid[i][j-1] == '1' && color[i][j-1]==0)
        bfs_visit(i,j-1);
    if(j!= gsize_col-1 && ggrid[i][j+1] == '1' && color[i][j+1]==0)
        bfs_visit(i,j+1);
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        ggrid = grid;
        vector<vector<int>> temp(grid.size(),vector<int>(grid[0].size(),0));
        color = temp;
        int noi = 0;
        gsize_row = grid.size();
        gsize_col = grid[0].size();
        for(int i=0;i<gsize_row;i++)
        {
            for(int j=0;j<gsize_col;j++)
            {
                // cout<<ggrid[i][j]<<" "<<color[i][j]<<" "<<i<<":"<<j<<endl;
                if(ggrid[i][j] == '1' && color[i][j]==0)
                {
                    noi++;
                    //BFS on this island
                    bfs_visit(i,j);
                    
                }
            }
        }
        return noi;
    }
};
