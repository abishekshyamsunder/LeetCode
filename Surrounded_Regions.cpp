class Solution {
public:
    vector<vector<int>> color;
    vector<vector<char>> gboard;
    int m,n;
    void dfs_visit(int i, int j)
    {
        color[i][j] = 1;
        if(i!=0 && gboard[i-1][j]=='O' && color[i-1][j]==0)
        {
            dfs_visit(i-1,j);    
        }
        if(i!=m-1 && gboard[i+1][j]=='O' && color[i+1][j]==0)
        {
            dfs_visit(i+1,j);    
        }
        if(j!=0 && gboard[i][j-1]=='O' && color[i][j-1]==0)
        {
            dfs_visit(i,j-1);    
        }
        if(j!=n-1 && gboard[i][j+1]=='O' && color[i][j+1]==0)
        {
            dfs_visit(i,j+1);    
        }
        color[i][j] = 2;
    }
    
    void solve(vector<vector<char>>& board) {
        color = vector<vector<int>>(board.size(), vector<int>(board[0].size(),0));
        gboard = board;
        m = board.size();
        n = board[0].size();
        //go over egde and call dfs_visit on all O nodes
        for(int j=0;j<n;j++)
        {
            if(gboard[0][j]=='O' && color[0][j]==0)
                dfs_visit(0,j);
        }
        for(int j=0;j<n;j++)
        {
            if(gboard[m-1][j]=='O' && color[m-1][j]==0)
                dfs_visit(m-1,j);
        }
        for(int i=0;i<m;i++)
        {
            if(gboard[i][0]=='O' && color[i][0]==0)
                dfs_visit(i,0);
        }
        for(int i=0;i<m;i++)
        {
            if(gboard[i][n-1]=='O' && color[i][n-1]==0)
                dfs_visit(i,n-1);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(color[i][j] != 2)
                    board[i][j] = 'X';
            }
        }
        // board = gboard;
    }
};
