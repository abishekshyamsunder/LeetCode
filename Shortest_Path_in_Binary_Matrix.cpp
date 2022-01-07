class Solution {
public:
    vector<vector<int>> ggrid;
    vector<vector<int>> color;
    vector<vector<int>> len;
    int size;
//     int bfs_visit(int i, int j, length)
//     {
//         length = length+1;
//         if(i == size-1 && j == size-1)
//             return length;
//         color[i][j] = 1;
//         if(i!=0)
//         {
//             bfs_visit(i-1,j,0)
//         }
        
//     }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ggrid = grid;
        size = grid.size();
        // vector<vector<int>> tempc(vector<int>(size,0),0);
        // color = tempc;
        vector<vector<int>> tempc(size,vector<int>(size,0));
        color = tempc;
        
        len = vector<vector<int>>(size,vector<int>(size,-1));
        // int len;
        if(grid[0][0] == 1)
            return -1;
        if(size==1)
            return 1;
        vector<pair<int,int>> q;
        q.push_back(make_pair(0,0));
        len[0][0] = 1;
        color[0][0] = 1;
        while(q.size()!=0)
        {
            pair<int,int> temp;
            temp = q[0];
            q.erase(q.begin());
            int i = temp.first;
            int j = temp.second;
            
            // color[i][j] = 1;
            if(i==0)
            {
                //i==0 && j==0
                if(j==0)
                {
                    if(grid[i][j+1]==0 && color[i][j+1]==0)
                    {
                        color[i][j+1] = 1;
                        len[i][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i,j+1));
                    }
                    if(grid[i+1][j+1]==0 && color[i+1][j+1]==0)
                    {
                        color[i+1][j+1] = 1;
                        len[i+1][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j+1));
                    }
                    if(grid[i+1][j]==0 && color[i+1][j]==0)
                    {
                        color[i+1][j] = 1;
                        len[i+1][j] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j));
                    }
                }
                else if(j==size-1)
                {
                    if(grid[i+1][j]==0 && color[i+1][j]==0)
                    {
                        color[i+1][j] = 1;
                        len[i+1][j] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j));
                    }
                    if(grid[i+1][j-1]==0 && color[i+1][j-1]==0)
                    {
                        color[i+1][j-1] = 1;
                        len[i+1][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j-1));
                    }
                    if(grid[i][j-1]==0 && color[i][j-1]==0)
                    {
                        color[i][j-1] = 1;
                        len[i][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i,j-1));
                    }
                }
                else
                {
                    if(grid[i][j+1]==0 && color[i][j+1]==0)
                    {
                        color[i][j+1] = 1;
                        len[i][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i,j+1));
                    }
                    if(grid[i][j-1]==0 && color[i][j-1]==0)
                    {
                        color[i][j-1] = 1;
                        len[i][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i,j-1));
                    }
                    if(grid[i+1][j-1]==0 && color[i+1][j-1]==0)
                    {
                        color[i+1][j-1] = 1;
                        len[i+1][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j-1));
                    }
                    if(grid[i+1][j]==0 && color[i+1][j]==0)
                    {
                        color[i+1][j] = 1;
                        len[i+1][j] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j));
                    }
                    if(grid[i+1][j+1]==0 && color[i+1][j+1]==0)
                    {
                        color[i+1][j+1] = 1;
                        len[i+1][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j+1));
                    }
                }
            
            }
            else if(i == size-1)
            {
                if(j==0)
                {
                    if(grid[i][j+1]==0 && color[i][j+1]==0)
                    {
                        color[i][j+1] = 1;
                        len[i][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i,j+1));
                    }
                    if(grid[i-1][j+1]==0 && color[i-1][j+1]==0)
                    {
                        color[i-1][j+1] = 1;
                        len[i-1][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j+1));
                    }
                    if(grid[i-1][j]==0 && color[i-1][j]==0)
                    {
                        color[i-1][j] = 1;
                        len[i-1][j] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j));
                    }
                }
                else if(j==size-1)
                {
                    break;
                    if(grid[i-1][j]==0 && color[i-1][j]==0)
                    {
                        color[i-1][j] = 1;
                        len[i-1][j] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j));
                    }
                    if(grid[i-1][j-1]==0 && color[i-1][j-1]==0)
                    {
                        color[i-1][j-1] = 1;
                        len[i-1][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j-1));
                    }
                    if(grid[i][j-1]==0 && color[i][j-1]==0)
                    {
                        color[i][j-1] = 1;
                        len[i][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i,j-1));
                    }
                }
                else
                {
                    if(grid[i][j+1]==0 && color[i][j+1]==0)
                    {
                        color[i][j+1] = 1;
                        len[i][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i,j+1));
                    }
                    if(grid[i][j-1]==0 && color[i][j-1]==0)
                    {
                        color[i][j-1] = 1;
                        len[i][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i,j-1));
                    }
                    if(grid[i-1][j-1]==0 && color[i-1][j-1]==0)
                    {
                        color[i-1][j-1] = 1;
                        len[i-1][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j-1));
                    }
                    if(grid[i-1][j]==0 && color[i-1][j]==0)
                    {
                        color[i-1][j] = 1;
                        len[i-1][j] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j));
                    }
                    if(grid[i-1][j+1]==0 && color[i-1][j+1]==0)
                    {
                        color[i-1][j+1] = 1;
                        len[i-1][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j+1));
                    }
                }
            }
            else
            {
                if(j==0)
                {
                    if(grid[i][j+1]==0 && color[i][j+1]==0)
                    {
                        color[i][j+1] = 1;
                        len[i][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i,j+1));
                    }
                    if(grid[i-1][j+1]==0 && color[i-1][j+1]==0)
                    {
                        color[i-1][j+1] = 1;
                        len[i-1][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j+1));
                    }
                    if(grid[i-1][j]==0 && color[i-1][j]==0)
                    {
                        color[i-1][j] = 1;
                        len[i-1][j] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j));
                    }
                    if(grid[i+1][j+1]==0 && color[i+1][j+1]==0)
                    {
                        color[i+1][j+1] = 1;
                        len[i+1][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j+1));
                    }
                    if(grid[i+1][j]==0 && color[i+1][j]==0)
                    {
                        color[i+1][j] = 1;
                        len[i+1][j] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j));
                    }
                }
                else if(j==size-1)
                {
                    if(grid[i+1][j]==0 && color[i+1][j]==0)
                    {
                        color[i+1][j] = 1;
                        len[i+1][j] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j));
                    }
                    if(grid[i+1][j-1]==0 && color[i+1][j-1]==0)
                    {
                        color[i+1][j-1] = 1;
                        len[i+1][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j-1));
                    }
                    if(grid[i][j-1]==0 && color[i][j-1]==0)
                    {
                        color[i][j-1] = 1;
                        len[i][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i,j-1));
                    }
                    if(grid[i-1][j]==0 && color[i-1][j]==0)
                    {
                        color[i-1][j] = 1;
                        len[i-1][j] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j));
                    }
                    if(grid[i-1][j-1]==0 && color[i-1][j-1]==0)
                    {
                        color[i-1][j-1] = 1;
                        len[i-1][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j-1));
                    }
                }
                else
                {
                    if(grid[i][j+1]==0 && color[i][j+1]==0)
                    {
                        color[i][j+1] = 1;
                        len[i][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i,j+1));
                    }
                    if(grid[i][j-1]==0 && color[i][j-1]==0)
                    {
                        color[i][j-1] = 1;
                        len[i][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i,j-1));
                    }
                    if(grid[i+1][j-1]==0 && color[i+1][j-1]==0)
                    {
                        color[i+1][j-1] = 1;
                        len[i+1][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j-1));
                    }
                    if(grid[i+1][j]==0 && color[i+1][j]==0)
                    {
                        color[i+1][j] = 1;
                        len[i+1][j] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j));
                    }
                    if(grid[i+1][j+1]==0 && color[i+1][j+1]==0)
                    {
                        color[i+1][j+1] = 1;
                        len[i+1][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i+1,j+1));
                    }
                    if(grid[i-1][j-1]==0 && color[i-1][j-1]==0)
                    {
                        color[i-1][j-1] = 1;
                        len[i-1][j-1] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j-1));
                    }
                    if(grid[i-1][j]==0 && color[i-1][j]==0)
                    {
                        color[i-1][j] = 1;
                        len[i-1][j] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j));
                    }
                    if(grid[i-1][j+1]==0 && color[i-1][j+1]==0)
                    {
                        color[i-1][j+1] = 1;
                        len[i-1][j+1] = len[i][j]+1;
                        q.push_back(make_pair(i-1,j+1));
                    }
                }
            }
            
                
        }
        return len[size-1][size-1];
    }
};
