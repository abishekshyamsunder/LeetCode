class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int s = 0;
        int e = 0;
        int prev = 0;
        vector<int> dp(nums.size(),0);
        while(e<nums.size())
        {
            if(e-s+1<3)
            {
                if(e == 0)
                    dp[e] = 0;
                else
                    dp[e] = dp[e-1];
                e++;
            }
            else
            {
               if((nums[e]-nums[e-1]) == (nums[e-1]-nums[e-2]))
               {
                   dp[e] = dp[e-1] + (e-s-1);
                   e++;
               }
                else
                {
                    dp[e] = dp[e-1];
                    s++;
                }
            }
        }
        return dp[nums.size()-1];
    }
};
