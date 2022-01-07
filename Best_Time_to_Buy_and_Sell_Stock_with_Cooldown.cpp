class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        vector<int> s0(prices.size(),0);
        vector<int> s1(prices.size(),0);
        vector<int> s2(prices.size(),0);
        s0[0] = 0;
        s1[0] = -prices[0];
        s2[0] = 0;
        for(int i=1;i<prices.size();i++)
        {
            s0[i] = max(s2[i-1], s0[i-1]);
            s1[i] = max(s1[i-1], s0[i-1] - prices[i]);
            s2[i] = s1[i-1] + prices[i];
        }
        for(int i=0;i<prices.size();i++)
        {
            cout<<s0[i]<<"\t";
        }
        cout<<endl;
        for(int i=0;i<prices.size();i++)
        {
            cout<<s1[i]<<"\t";
        }
        cout<<endl;
        for(int i=0;i<prices.size();i++)
        {
            cout<<s2[i]<<"\t";
        }
        return max(s2[prices.size()-1],s0[prices.size()-1]);
    }
};
