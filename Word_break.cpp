class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length();
        vector<bool> dp(s.length(),false);
        for(int i = 0;i<size;i++)
        {
            for(int j=0;j<=i;j++)
            {
                string temp = s.substr (j,i-j+1);
                // cout<<j<<":"<<i<<" "<<temp<<endl;
                bool flag = false;
                for(int k=0;k<wordDict.size();k++)
                {
                    if(temp == wordDict[k])
                    {
                        flag = true;
                        break;
                    }
                }
                if(j == 0)
                    dp[i] = (dp[i] || flag);
                else
                    dp[i] = (dp[i] || (flag && dp[j-1]));
            }
        }
        return dp[size-1];   
    }
};
