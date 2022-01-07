class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_sum = 0;
        int min_ind = 0;
        int max_ind = 0;
        bool flag = false;
        for(int i=1;i<prices.size();i++)
        {
            // if(prices[i]<prices[min_ind])
            // {
            //     min_ind = i;
            //     max_ind = i;
            // }
            if(prices[i]>prices[max_ind])
            {
                max_ind = i;
                flag = true;
            }
            else if(prices[i]<prices[max_ind])
            {
                // cout<<"here";
                total_sum = total_sum + prices[max_ind]-prices[min_ind];
                max_ind = i;
                min_ind = i;
                flag = false;
            }
        }
        if(flag == true)
            total_sum = total_sum + prices[max_ind]-prices[min_ind];
        return total_sum;
        
    }
};
