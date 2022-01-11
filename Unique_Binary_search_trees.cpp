class Solution {
public:
    int numTrees(int n) {
        vector<int> DP(n+1, 1);
        for(int k=1;k<=n;k++)
        {
            int sum = 0;
            for(int i = 1;i<=k;i++)
            {
                sum = sum + DP[i-1]*DP[k-i];
                // cout<<i<<"->"<<sum<<": "<<DP[i-1]<<"*"<<DP[k-i]<<endl;
            }
            DP[k] = sum;
            // cout<<endl<<k<<":"<<DP[k]<<endl;
        }
        return DP[n];
        
    }
};
