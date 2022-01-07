class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ind = 0;
        int max_ind = 0;
        int ret_val = 0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<prices[min_ind])
            {
                min_ind = i;
                max_ind = i;
            }
            else if(prices[i]>prices[max_ind])
            {
                max_ind = i;
            }
            ret_val = max(ret_val, prices[max_ind]-prices[min_ind]);
            
        }
        return ret_val;
    }
    
};
