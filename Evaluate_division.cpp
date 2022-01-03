#define INF 99999
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> names;
        set<string> s;
        vector<double> ret;
        
        //creating weight matrix
        for(int i=0;i<equations.size();i++)
        {
            s.insert(equations[i][0]);
            s.insert(equations[i][1]);
        }
        int i = 0;
        for (auto elem : s)
        {
            names.insert({ elem, i });
            cout<<elem<<":"<<i<<endl;
            i++;
        }
        int mat_size = names.size();
        vector<vector<double>> w(mat_size,vector<double>(mat_size, INF));
        
        for(int k=0;k<equations.size();k++)
        {
            auto i = names.find(equations[k][0]);
            auto j = names.find(equations[k][1]);
            
            // cout<<i->second<<" "<<j->second;
            w[i->second][j->second] = values[k];
            w[j->second][i->second] = 1.0/values[k];
        }
        // for(i=0;i<w.size();i++)
        // {
        //     for(int j=0;j<w.size();j++)
        //     {
        //         cout<<w[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int k,j;
        //Floyd Warshall
        for (k = 0; k < mat_size; k++) {
            // Pick all vertices as source one by one
            for (i = 0; i < mat_size; i++) {
                // Pick all vertices as destination for the
                // above picked source
                for (j = 0; j < mat_size; j++) {
                    // If vertex k is on the shortest path from
                    // i to j, then update the value of
                    // dist[i][j]
                    if (w[i][j] > (w[i][k] * w[k][j])
                        && (w[k][j] != INF
                            && w[i][k] != INF))
                        w[i][j] = w[i][k] * w[k][j];
                }
            }
        }
        
        // for(i=0;i<w.size();i++)
        // {
        //     for(int j=0;j<w.size();j++)
        //     {
        //         cout<<w[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int k=0;k<queries.size();k++)
        {
            auto i = names.find(queries[k][0]);
            auto j = names.find(queries[k][1]);
            
            // map<string,int>::iterator i = names.find(queries[k][0]);
            // map<string,int>::iterator j = names.find(queries[k][1]);
            
            // cout<<i->second<<" "<<j->second;
            if(i==names.end() || j==names.end())
                ret.push_back(-1.0);
            else
            {
                if(w[i->second][j->second] != 99999)
                    ret.push_back(w[i->second][j->second]);
                else
                    ret.push_back(-1);
                // w[j->second][i->second] = 1.0/values[k];    
            }
            
        }
        return ret;
    }
};
