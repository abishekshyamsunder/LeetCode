vector<vector<int>> ggrid;
vector<int> color;
int gsize_row;
int gsize_col;
void bfs_visit(int i)
{
    // noi++;
    color[i] = 1;
    for(int k = 0;k<gsize_col;k++)
    {
        if(ggrid[i][k] == 1 && color[k]==0)
            bfs_visit(k);
    }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        ggrid = isConnected;
        vector<int> temp(ggrid.size(),0);
        color = temp;
        int noi = 0;
        gsize_row = ggrid.size();
        gsize_col = ggrid[0].size();
        for(int i=0;i<gsize_row;i++)
        {
            for(int j=0;j<gsize_col;j++)
            {
                // cout<<ggrid[i][j]<<" "<<color[i][j]<<" "<<i<<":"<<j<<endl;
                if(ggrid[i][j] == 1 && color[j]==0)
                {
                    noi++;
                    //BFS on this island
                    bfs_visit(j);
                    
                }
            }
        }
        return noi;
        
    }
};
