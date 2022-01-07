class Solution {
public:
    int start;
    int end;
    vector<vector<int>> ggraph;
    vector<int> color;
    vector<vector<int>> ret_val;
    void dfs_visit(int i, vector<int> path)
    {
        path.push_back(i);
        if(i==end)
            ret_val.push_back(path);
        for(int j=0;j<ggraph[i].size();j++)
        {
            dfs_visit(ggraph[i][j], path);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        ggraph = graph;
        end = 0;
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                end = max(end,graph[i][j]);
            }
        }
        
        dfs_visit(0,vector<int>());
        return ret_val;
    }
};
