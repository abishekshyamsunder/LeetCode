class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int max_num=INT_MIN;
        vector<int> parent(1002,0);
        for(int i=1;i<1002;i++)
            parent[i] = i;
        int temp = INT_MAX;
        int temp2;
        int v1,v2;
        for(int i=0;i<edges.size();i++)
        {
            max_num = max(max_num,edges[i][0]);
            max_num = max(max_num,edges[i][1]);
            // cout<<"m: "<<max_num<<endl;
            v1 = edges[i][0];
            v2 = edges[i][1];
            // cout<<v1<<":"<<parent[v1]<<" "<<v2<<":"<<parent[v2]<<endl;
            if(parent[v1]!=parent[v2])
            {
                if(parent[v1]<parent[v2])
                {
                    temp2 = parent[v2];
                    for(int j=1;j<=max_num;j++)
                    {
                        if(parent[j]==temp2)
                            parent[j]=parent[v1];
                    }
                }
                else
                {
                    temp2 = parent[v1];
                    for(int j=1;j<=max_num;j++)
                    {
                        if(parent[j]==temp2)
                            parent[j]=parent[v2];
                    }
                }
                
            }
            else
                return edges[i];
            // cout<<v1<<":"<<parent[v1]<<" "<<v2<<":"<<parent[v2]<<endl;
            // cout<<"---"<<endl;
            for(int i=1;i<6;i++)
                cout<<parent[i]<<" ";
            cout<<endl;
        }
        return vector<int>(2,-1);
        
        
    }
};
